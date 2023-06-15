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

static bool internal_hf_string_lookup_range(char* input, const long* table, size_t table_size, bool to_upper) {
    for(size_t i = 0; i < table_size; i++) {
        size_t key_start_index = to_upper ? ((i * 4) + 2) : (i * 4);
        size_t key_end_index = to_upper ? ((i * 4) + 3) : ((i * 4) + 1);
        size_t val_start_index = to_upper ? (i * 4) : ((i * 4) + 2);

        long key_start_unicode = table[key_start_index];
        long key_end_unicode = table[key_end_index];
        long val_start_unicode = table[val_start_index];

        long input_unicode = internal_hf_string_utf8_to_unicode(input);
        long diff = val_start_unicode - key_start_unicode;

        if(input_unicode >= key_start_unicode && input_unicode <= key_end_unicode) {
            internal_hf_string_set_utf8_from_unicode(input, input_unicode + diff);
            return true;
        }
    }
    return false;
}

static bool internal_hf_string_lookup_alternating(char* input, const long* table, size_t table_size, bool to_upper) {
    for(size_t i = 0; i < table_size; i++) {
        size_t key_start_index = i * 2;
        size_t key_end_index = (i * 2) + 1;

        long key_start_unicode = table[key_start_index] + (to_upper ? 1 : 0);
        long key_end_unicode = table[key_end_index] + (to_upper ? 1 : 0);

        long input_unicode = internal_hf_string_utf8_to_unicode(input);

        if(input_unicode >= key_start_unicode && input_unicode <= key_end_unicode && ((input_unicode - key_start_unicode) % 2) == 0) {
            internal_hf_string_set_utf8_from_unicode(input, input_unicode + (to_upper ? -1 : 1));
            return true;
        }
    }
    return false;
}

static bool internal_hf_string_lookup_manual(char* input, const long* table, size_t table_size, bool to_upper) {
    for(size_t i = 0; i < table_size; i++) {
        size_t key_index = to_upper ? ((i * 2) + 1) : (i * 2);
        size_t val_index = to_upper ? (i * 2) : ((i * 2) + 1);

        long key_unicode = table[key_index];
        long input_unicode = internal_hf_string_utf8_to_unicode(input);

        if(input_unicode == key_unicode) {
            long val = table[val_index];
            internal_hf_string_set_utf8_from_unicode(input, val);
            return true;
        }
    }
    return false;
}

static bool internal_hf_string_to_case(const char* string, char* buffer, size_t buffer_size, bool to_upper) {
    if(buffer_size == 0) {
        return false;
    }

    //auto-generated conversion tables based on https://www.unicode.org/Public/UCD/latest/ucd/UnicodeData.txt
    long range_table[] = {
        65, 90, 97, 122,
        192, 214, 224, 246,
        216, 222, 248, 254,
        393, 394, 598, 599,
        433, 434, 650, 651,
        904, 906, 941, 943,
        910, 911, 973, 974,
        913, 939, 945, 971,
        1021, 1023, 891, 893,
        1024, 1039, 1104, 1119,
        1040, 1071, 1072, 1103,
        1329, 1366, 1377, 1414,
        4256, 4301, 11520, 11565,
        5024, 5103, 43888, 43967,
        5104, 5109, 5112, 5117,
        7312, 7359, 4304, 4351,
        7944, 7951, 7936, 7943,
        7960, 7965, 7952, 7957,
        7976, 7983, 7968, 7975,
        7992, 7999, 7984, 7991,
        8008, 8013, 8000, 8005,
        8040, 8047, 8032, 8039,
        8072, 8079, 8064, 8071,
        8088, 8095, 8080, 8087,
        8104, 8111, 8096, 8103,
        8120, 8121, 8112, 8113,
        8122, 8123, 8048, 8049,
        8136, 8139, 8050, 8053,
        8152, 8153, 8144, 8145,
        8154, 8155, 8054, 8055,
        8168, 8169, 8160, 8161,
        8170, 8171, 8058, 8059,
        8184, 8185, 8056, 8057,
        8186, 8187, 8060, 8061,
        8544, 8559, 8560, 8575,
        9398, 9423, 9424, 9449,
        11264, 11311, 11312, 11359,
        11390, 11391, 575, 576,
        65313, 65338, 65345, 65370,
        66560, 66599, 66600, 66639,
        66736, 66771, 66776, 66811,
        66928, 66965, 66967, 67004,
        68736, 68786, 68800, 68850,
        71840, 71871, 71872, 71903,
        93760, 93791, 93792, 93823,
        125184, 125217, 125218, 125251,
    };
    const size_t range_table_len = sizeof(range_table) / sizeof(range_table[0]) / 4;

    long alternating_table[] = {
        256, 302,
        306, 310,
        313, 327,
        330, 374,
        377, 381,
        386, 388,
        391, 391,
        395, 395,
        401, 401,
        408, 408,
        416, 420,
        423, 423,
        428, 428,
        431, 431,
        435, 437,
        440, 440,
        444, 444,
        453, 453,
        456, 456,
        459, 475,
        478, 494,
        498, 500,
        504, 542,
        546, 562,
        571, 571,
        577, 577,
        582, 590,
        880, 882,
        886, 886,
        984, 1006,
        1015, 1015,
        1018, 1018,
        1120, 1152,
        1162, 1214,
        1217, 1229,
        1232, 1326,
        7680, 7828,
        7840, 7934,
        8579, 8579,
        11360, 11360,
        11367, 11371,
        11378, 11378,
        11381, 11381,
        11392, 11490,
        11499, 11501,
        11506, 11506,
        42560, 42604,
        42624, 42650,
        42786, 42798,
        42802, 42862,
        42873, 42875,
        42878, 42886,
        42891, 42891,
        42896, 42898,
        42902, 42920,
        42932, 42946,
        42951, 42960,
        42966, 42968,
        42997, 42997,
    };
    const size_t alternating_table_len = sizeof(alternating_table) / sizeof(alternating_table[0]) / 2;

    long direct_table[] = {
        304, 105,
        376, 255,
        385, 595,
        390, 596,
        398, 477,
        399, 601,
        400, 603,
        403, 608,
        404, 611,
        406, 617,
        407, 616,
        412, 623,
        413, 626,
        415, 629,
        422, 640,
        425, 643,
        430, 648,
        439, 658,
        452, 454,
        455, 457,
        458, 460,
        497, 499,
        502, 405,
        503, 447,
        544, 414,
        570, 11365,
        573, 410,
        574, 11366,
        579, 384,
        580, 649,
        581, 652,
        895, 1011,
        902, 940,
        908, 972,
        975, 983,
        1012, 952,
        1017, 1010,
        1216, 1231,
        7838, 223,
        8025, 8017,
        8027, 8019,
        8029, 8021,
        8031, 8023,
        8124, 8115,
        8140, 8131,
        8172, 8165,
        8188, 8179,
        8486, 969,
        8490, 107,
        8491, 229,
        8498, 8526,
        11362, 619,
        11363, 7549,
        11364, 637,
        11373, 593,
        11374, 625,
        11375, 592,
        11376, 594,
        42877, 7545,
        42893, 613,
        42922, 614,
        42923, 604,
        42924, 609,
        42925, 620,
        42926, 618,
        42928, 670,
        42929, 647,
        42930, 669,
        42931, 43859,
        42948, 42900,
        42949, 642,
        42950, 7566,
    };
    const size_t direct_table_len = sizeof(direct_table) / sizeof(direct_table[0]) / 2;

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

        internal_hf_string_lookup_range(buffer_itr, range_table, range_table_len, to_upper) ||
        internal_hf_string_lookup_alternating(buffer_itr, alternating_table, alternating_table_len, to_upper) ||
        internal_hf_string_lookup_manual(buffer_itr, direct_table, direct_table_len, to_upper);
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
