#include "../include/hf_string.h"

#define HF_STRING_MASK_UTF8_START ((1 << 7) | (1 << 6))
#define HF_STRING_MASK_UTF8_CONTINUATION (1 << 7)

bool hf_string_equal(const char* left, const char* right) {
    while(*left && *right) {
        if(*left != *right) {
            return false;
        }
        left++;
        right++;
    }
    return *left == *right;
}

size_t hf_string_length_bytes(const char* string) {
    size_t len = 0;
    while(*string) {
        string++;
        len++;
    }
    return len;
}

size_t hf_string_length_codepoints(const char* string) {
    size_t len = 0;
    while(*string) {
        if((*(string++) & HF_STRING_MASK_UTF8_START) == HF_STRING_MASK_UTF8_START) {//
            do {
                string++;
            } while((*string & HF_STRING_MASK_UTF8_START) == HF_STRING_MASK_UTF8_CONTINUATION);
        }

        len++;
    }
    return len;
}

bool hf_string_copy(const char* string, char* buffer, size_t buffer_size) {
    if(buffer_size == 0) {
        return false;
    }

    size_t index = 0;
    while(index < (buffer_size - 1) && *string) {
        buffer[index++] = *string;
        string++;
    }
    bool retval = !(*string);
    while((*string & HF_STRING_MASK_UTF8_START) == HF_STRING_MASK_UTF8_CONTINUATION) {//push index back to start of codepoint if applicable
        string--;
        index--;
    }
    buffer[index] = '\0';
    return retval;
}

bool hf_string_concat(const char* string, char* buffer, size_t buffer_size) {
    size_t new_len = buffer_size;
    while(*buffer && new_len > 0) {
        buffer++;
        new_len--;
    }
    return hf_string_copy(string, buffer, new_len);
}

static bool internal_hf_string_lookup_manual(char* input, const char** table, size_t table_size, bool to_upper) {
    for(size_t i = 0; i < table_size; i++) {
        size_t key_index = to_upper ? ((i * 2) + 1) : (i * 2);
        size_t val_index = to_upper ? (i * 2) : ((i * 2) + 1);

        const char* input_itr = input;
        const char* table_itr = table[key_index];
        while(*input_itr && *table_itr) {
            if(*input_itr != *table_itr) {
                break;
            }

            input_itr++;
            table_itr++;
        }
        if(!(*table_itr)) {//found match, copy value to input
            const char* val_itr = table[val_index];
            char* buf_itr = input;
            while(*val_itr) {
                *buf_itr = *val_itr;
                val_itr++;
                buf_itr++;
            }
            return true;
        }
    }
    return false;
}

//will convert a utf8 character to a unicode codepoint and return it
static long internal_hf_string_utf8_to_unicode(const char* string) {
    int set_bits = 0;
    for(int i = 0; i < 4; i++) {
        if(((*string) >> (7 - i)) & 1) {
            set_bits++;
        }
        else {
            break;
        }
    }

    long retval = 0;
    long shift = 0;
    for(int i = (set_bits > 0 ? set_bits - 1 : 0); i >= 0; i--) {
        const char byte = string[i];
        int num_bits = i == 0 ? (7 - set_bits) : 6;
        for(int b = 0; b < num_bits; b++) {
            if((byte >> b) & 1) {
                retval |= (1L << shift);
            }
            shift++;
        }
    }
    return retval;
}

//will set string to the utf8 string corresponding to the provided unicode codepoint
static void internal_hf_string_set_utf8_from_unicode(char* string, long unicode) {
    int required_bits = 0;
    for(int i = 0; i < (int)(sizeof(unsigned long) * 8); i++) {
        if((unicode >> i) & 1) {
            required_bits = i + 1;
        }
    }

    int required_bytes = required_bits <= 7 ? 1 : (required_bits <= 11 ? 2 : (required_bits <= 16 ? 3 : 4));
    unsigned int shift = 0;
    for(int i = required_bytes - 1; i >= 0; i--) {
        char* byte_ptr = string + i;
        *byte_ptr = 0;
        if(i == 0 && required_bytes > 1) {//set initial string bits
            for(int b = 0; b < required_bytes; b++) {
                *byte_ptr |= 1 << (7 - b);
            }
        }
        else if(i != 0) {//set continuation bits
            *byte_ptr |= HF_STRING_MASK_UTF8_CONTINUATION;
        }

        int num_bits = required_bytes == 1 ? 7 : (i == 0 ? 7 - required_bytes : 6);
        for(int b = 0; b < num_bits; b++) {
            *byte_ptr |= (((unicode >> shift) & 1) << b);
            shift++;
        }
    }
}

static bool internal_hf_string_lookup_range(char* input, const char** table, size_t table_size, bool to_upper, int stride) {
    for(size_t i = 0; i < table_size; i++) {
        size_t key_start_index = to_upper ? ((i * 4) + 2) : (i * 4);
        size_t key_end_index = to_upper ? ((i * 4) + 3) : ((i * 4) + 1);
        size_t val_start_index = to_upper ? (i * 4) : ((i * 4) + 2);

        long key_start_unicode = internal_hf_string_utf8_to_unicode(table[key_start_index]);
        long key_end_unicode = internal_hf_string_utf8_to_unicode(table[key_end_index]);
        long val_start_unicode = internal_hf_string_utf8_to_unicode(table[val_start_index]);

        long input_unicode = internal_hf_string_utf8_to_unicode(input);
        long diff = val_start_unicode - key_start_unicode;

        if(input_unicode >= key_start_unicode && input_unicode <= key_end_unicode && (input_unicode - key_start_unicode) % stride == 0) {
            internal_hf_string_set_utf8_from_unicode(input, input_unicode + diff);
            return true;
        }
    }
    return false;
}

/*static bool internal_hf_string_lookup_alternating(char* input, const char** table, size_t table_size, bool to_upper) {

}*/

static bool internal_hf_string_to_case(const char* string, char* buffer, size_t buffer_size, bool to_upper) {
    if(buffer_size == 0) {
        return false;
    }

    //for ranges such as ascii A-Z a-z, where the one case is located a specific distance from the other
    const char* range_table[] = {
        "A", "Z", "a", "z",
        "À", "Ö", "à", "ö",
        "Ø", "Þ", "ø", "þ",
    };
    const size_t range_table_size = sizeof(range_table) / sizeof(range_table[0]) / 4;

    //for ranges where the the lowercase letter is immediately after the capital letter
    const char* alternating_table[] = {
        "Ā", "Ķ", "ā", "ķ",
        "Ĺ", "Ň", "ĺ", "ň",
        "Ŋ", "Ŷ", "ŋ", "ŷ",
        "Ź", "Ž", "ź", "ž",
        "Ƃ", "Ƅ", "ƃ", "ƅ",
        "Ǝ", "Ə", "ɘ", "ə",
        "Ơ", "Ƥ", "ơ", "ƥ",
    };
    const size_t alternating_table_size = sizeof(alternating_table) / sizeof(alternating_table[0]) / 2;
    (void)alternating_table_size;// TODO:

    //for cases where no previos rule may apply and cases are arbitrarily placed :(
    const char* manual_table[] = {
        "Ÿ", "ÿ",
        "Ƀ", "ƀ",
        "Ɓ", "ɓ",
        "Ɔ", "ɔ",
        "Ƈ", "ƈ",
        "Ɗ", "ɗ",
        "Ƌ", "ƌ",
        "Ɛ", "ɛ",
        "Ƒ", "ƒ",
        "Ɠ", "ɠ",
        "Ɣ", "Γ",
        "Ɩ", "ɩ",
        "Ɨ", "ɨ",
        "Ƙ", "ƙ",
        "Ƚ", "ƚ",
        "Ɯ", "ɯ",
        "Ɲ", "ɲ",
        "Ɵ", "ɵ",
        "Ƞ", "ƞ",
        "Ƨ", "ƨ",
        "Ʃ", "ʃ",// <----- STOPPED AT LATIN CAPITAL LETTER ESH
        // TODO: add remaining characters LOL
    };
    const size_t manual_table_size = sizeof(manual_table) / sizeof(manual_table[0]) / 2;

    size_t buffer_index = 0;
    bool retval = true;

    const char* itr = string;
    while(*itr) {
        if(buffer_index >= (buffer_size - 1)) {
            retval = false;
            break;
        }

        char* buffer_itr = &buffer[buffer_index];
        do {//copy original codepoint to buffer
            if(buffer_index >= (buffer_size - 1)) {//could not fit buffer, erase previous codepoint
                retval = false;
                while((buffer[buffer_index] & HF_STRING_MASK_UTF8_START) != HF_STRING_MASK_UTF8_START && buffer_index > 0) {
                    buffer_index--;
                }
                goto out;
            }
            buffer[buffer_index++] = *itr;
            itr++;
        } while((*itr & HF_STRING_MASK_UTF8_START) == HF_STRING_MASK_UTF8_CONTINUATION);

        internal_hf_string_lookup_range(buffer_itr, range_table, range_table_size, to_upper, 1) ||
        internal_hf_string_lookup_range(buffer_itr, alternating_table, alternating_table_size, to_upper, 2) ||
        internal_hf_string_lookup_manual(buffer_itr, manual_table, manual_table_size, to_upper);
    }
    out:

    buffer[buffer_index] = '\0';
    return retval;
}

bool hf_string_to_lower(const char* string, char* buffer, size_t buffer_size) {
    return internal_hf_string_to_case(string, buffer, buffer_size, false);
}

bool hf_string_to_upper(const char* string, char* buffer, size_t buffer_size) {
    return internal_hf_string_to_case(string, buffer, buffer_size, true);
}
