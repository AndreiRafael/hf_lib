#include "../include/hf_mat.h"

#include <string.h>

void hf_mat1x2f_copy(HF_Mat1x2f mat, HF_Mat1x2f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 2);
}

void hf_mat1x2f_transpose(HF_Mat1x2f mat, HF_Mat2x1f out) {
	HF_Mat2x1f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 2; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 2);
}

void hf_mat1x2f_add(HF_Mat1x2f a, HF_Mat1x2f b, HF_Mat1x2f out) {
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 2; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat1x2f_multiply(HF_Mat1x2f mat, float scalar, HF_Mat1x2f out) {
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 2; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat1x2f_multiply_mat2f(HF_Mat1x2f a, HF_Mat2f b, HF_Mat1x2f out) {
	HF_Mat1x2f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 1; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 2);
}

void hf_mat1x2f_multiply_mat2x3f(HF_Mat1x2f a, HF_Mat2x3f b, HF_Mat1x3f out) {
	HF_Mat1x3f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 1; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 3);
}

void hf_mat1x2f_multiply_mat2x4f(HF_Mat1x2f a, HF_Mat2x4f b, HF_Mat1x4f out) {
	HF_Mat1x4f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 1; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat1x3f_copy(HF_Mat1x3f mat, HF_Mat1x3f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 3);
}

void hf_mat1x3f_transpose(HF_Mat1x3f mat, HF_Mat3x1f out) {
	HF_Mat3x1f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 3; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 3);
}

void hf_mat1x3f_add(HF_Mat1x3f a, HF_Mat1x3f b, HF_Mat1x3f out) {
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 3; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat1x3f_multiply(HF_Mat1x3f mat, float scalar, HF_Mat1x3f out) {
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 3; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat1x3f_multiply_mat3x2f(HF_Mat1x3f a, HF_Mat3x2f b, HF_Mat1x2f out) {
	HF_Mat1x2f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 1; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 2);
}

void hf_mat1x3f_multiply_mat3f(HF_Mat1x3f a, HF_Mat3f b, HF_Mat1x3f out) {
	HF_Mat1x3f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 1; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 3);
}

void hf_mat1x3f_multiply_mat3x4f(HF_Mat1x3f a, HF_Mat3x4f b, HF_Mat1x4f out) {
	HF_Mat1x4f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 1; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat1x4f_copy(HF_Mat1x4f mat, HF_Mat1x4f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 4);
}

void hf_mat1x4f_transpose(HF_Mat1x4f mat, HF_Mat4x1f out) {
	HF_Mat4x1f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 4; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat1x4f_add(HF_Mat1x4f a, HF_Mat1x4f b, HF_Mat1x4f out) {
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 4; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat1x4f_multiply(HF_Mat1x4f mat, float scalar, HF_Mat1x4f out) {
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 4; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat1x4f_multiply_mat4x2f(HF_Mat1x4f a, HF_Mat4x2f b, HF_Mat1x2f out) {
	HF_Mat1x2f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 1; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 2);
}

void hf_mat1x4f_multiply_mat4x3f(HF_Mat1x4f a, HF_Mat4x3f b, HF_Mat1x3f out) {
	HF_Mat1x3f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 1; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 3);
}

void hf_mat1x4f_multiply_mat4f(HF_Mat1x4f a, HF_Mat4f b, HF_Mat1x4f out) {
	HF_Mat1x4f tmp;
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 1; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat2x1f_copy(HF_Mat2x1f mat, HF_Mat2x1f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 2);
}

void hf_mat2x1f_transpose(HF_Mat2x1f mat, HF_Mat1x2f out) {
	HF_Mat1x2f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 1; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 2);
}

void hf_mat2x1f_add(HF_Mat2x1f a, HF_Mat2x1f b, HF_Mat2x1f out) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 1; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat2x1f_multiply(HF_Mat2x1f mat, float scalar, HF_Mat2x1f out) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 1; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat2x1f_multiply_mat1x2f(HF_Mat2x1f a, HF_Mat1x2f b, HF_Mat2f out) {
	HF_Mat2f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat2x1f_multiply_mat1x3f(HF_Mat2x1f a, HF_Mat1x3f b, HF_Mat2x3f out) {
	HF_Mat2x3f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 6);
}

void hf_mat2x1f_multiply_mat1x4f(HF_Mat2x1f a, HF_Mat1x4f b, HF_Mat2x4f out) {
	HF_Mat2x4f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 8);
}

void hf_mat2f_copy(HF_Mat2f mat, HF_Mat2f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 4);
}

void hf_mat2f_identity(HF_Mat2f out) {
	float values[] = {
		1.f, 0.f,
		0.f, 1.f,
	};
	memcpy(out, values, sizeof(out[0][0]) * 4);
}

void hf_mat2f_transpose(HF_Mat2f mat, HF_Mat2f out) {
	HF_Mat2f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

float hf_mat2f_determinant(HF_Mat2f mat) {

	return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

float hf_mat2f_minor(HF_Mat2f mat, int i, int j) {
	return mat[1 - i][1 - j];
}

void hf_mat2f_inverse(HF_Mat2f mat, HF_Mat2f out) {
	float det = hf_mat2f_determinant(mat);
	if(det == 0.0f) {
		return;
	}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			out[j][i] = ((i + j) % 2 == 0 ? 1.f : -1.f) * hf_mat2f_minor(mat, i, j);
		}
	}
	hf_mat2f_multiply(out, 1.f / det, out);
}

void hf_mat2f_add(HF_Mat2f a, HF_Mat2f b, HF_Mat2f out) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat2f_multiply(HF_Mat2f mat, float scalar, HF_Mat2f out) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat2f_multiply_mat2x1f(HF_Mat2f a, HF_Mat2x1f b, HF_Mat2x1f out) {
	HF_Mat2x1f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 1; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 2);
}

void hf_mat2f_multiply_mat2f(HF_Mat2f a, HF_Mat2f b, HF_Mat2f out) {
	HF_Mat2f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat2f_multiply_mat2x3f(HF_Mat2f a, HF_Mat2x3f b, HF_Mat2x3f out) {
	HF_Mat2x3f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 6);
}

void hf_mat2f_multiply_mat2x4f(HF_Mat2f a, HF_Mat2x4f b, HF_Mat2x4f out) {
	HF_Mat2x4f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 8);
}

void hf_mat2x3f_copy(HF_Mat2x3f mat, HF_Mat2x3f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 6);
}

void hf_mat2x3f_transpose(HF_Mat2x3f mat, HF_Mat3x2f out) {
	HF_Mat3x2f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 6);
}

void hf_mat2x3f_add(HF_Mat2x3f a, HF_Mat2x3f b, HF_Mat2x3f out) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat2x3f_multiply(HF_Mat2x3f mat, float scalar, HF_Mat2x3f out) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat2x3f_multiply_mat3x1f(HF_Mat2x3f a, HF_Mat3x1f b, HF_Mat2x1f out) {
	HF_Mat2x1f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 1; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 2);
}

void hf_mat2x3f_multiply_mat3x2f(HF_Mat2x3f a, HF_Mat3x2f b, HF_Mat2f out) {
	HF_Mat2f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat2x3f_multiply_mat3f(HF_Mat2x3f a, HF_Mat3f b, HF_Mat2x3f out) {
	HF_Mat2x3f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 6);
}

void hf_mat2x3f_multiply_mat3x4f(HF_Mat2x3f a, HF_Mat3x4f b, HF_Mat2x4f out) {
	HF_Mat2x4f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 8);
}

void hf_mat2x4f_copy(HF_Mat2x4f mat, HF_Mat2x4f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 8);
}

void hf_mat2x4f_transpose(HF_Mat2x4f mat, HF_Mat4x2f out) {
	HF_Mat4x2f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 8);
}

void hf_mat2x4f_add(HF_Mat2x4f a, HF_Mat2x4f b, HF_Mat2x4f out) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat2x4f_multiply(HF_Mat2x4f mat, float scalar, HF_Mat2x4f out) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat2x4f_multiply_mat4x1f(HF_Mat2x4f a, HF_Mat4x1f b, HF_Mat2x1f out) {
	HF_Mat2x1f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 1; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 2);
}

void hf_mat2x4f_multiply_mat4x2f(HF_Mat2x4f a, HF_Mat4x2f b, HF_Mat2f out) {
	HF_Mat2f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat2x4f_multiply_mat4x3f(HF_Mat2x4f a, HF_Mat4x3f b, HF_Mat2x3f out) {
	HF_Mat2x3f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 6);
}

void hf_mat2x4f_multiply_mat4f(HF_Mat2x4f a, HF_Mat4f b, HF_Mat2x4f out) {
	HF_Mat2x4f tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 8);
}

void hf_mat3x1f_copy(HF_Mat3x1f mat, HF_Mat3x1f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 3);
}

void hf_mat3x1f_transpose(HF_Mat3x1f mat, HF_Mat1x3f out) {
	HF_Mat1x3f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 1; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 3);
}

void hf_mat3x1f_add(HF_Mat3x1f a, HF_Mat3x1f b, HF_Mat3x1f out) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 1; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat3x1f_multiply(HF_Mat3x1f mat, float scalar, HF_Mat3x1f out) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 1; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat3x1f_multiply_mat1x2f(HF_Mat3x1f a, HF_Mat1x2f b, HF_Mat3x2f out) {
	HF_Mat3x2f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 6);
}

void hf_mat3x1f_multiply_mat1x3f(HF_Mat3x1f a, HF_Mat1x3f b, HF_Mat3f out) {
	HF_Mat3f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 9);
}

void hf_mat3x1f_multiply_mat1x4f(HF_Mat3x1f a, HF_Mat1x4f b, HF_Mat3x4f out) {
	HF_Mat3x4f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 12);
}

void hf_mat3x2f_copy(HF_Mat3x2f mat, HF_Mat3x2f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 6);
}

void hf_mat3x2f_transpose(HF_Mat3x2f mat, HF_Mat2x3f out) {
	HF_Mat2x3f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 6);
}

void hf_mat3x2f_add(HF_Mat3x2f a, HF_Mat3x2f b, HF_Mat3x2f out) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat3x2f_multiply(HF_Mat3x2f mat, float scalar, HF_Mat3x2f out) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat3x2f_multiply_mat2x1f(HF_Mat3x2f a, HF_Mat2x1f b, HF_Mat3x1f out) {
	HF_Mat3x1f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 1; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 3);
}

void hf_mat3x2f_multiply_mat2f(HF_Mat3x2f a, HF_Mat2f b, HF_Mat3x2f out) {
	HF_Mat3x2f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 6);
}

void hf_mat3x2f_multiply_mat2x3f(HF_Mat3x2f a, HF_Mat2x3f b, HF_Mat3f out) {
	HF_Mat3f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 9);
}

void hf_mat3x2f_multiply_mat2x4f(HF_Mat3x2f a, HF_Mat2x4f b, HF_Mat3x4f out) {
	HF_Mat3x4f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 12);
}

void hf_mat3f_copy(HF_Mat3f mat, HF_Mat3f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 9);
}

void hf_mat3f_identity(HF_Mat3f out) {
	float values[] = {
		1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 0.f, 1.f,
	};
	memcpy(out, values, sizeof(out[0][0]) * 9);
}

void hf_mat3f_transpose(HF_Mat3f mat, HF_Mat3f out) {
	HF_Mat3f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 9);
}

float hf_mat3f_determinant(HF_Mat3f mat) {
	HF_Mat2f mat_0, mat_1, mat_2;
	memcpy(&mat_0[0][0], &mat[1][1], sizeof(mat[0][0]) * 2);
	memcpy(&mat_0[1][0], &mat[2][1], sizeof(mat[0][0]) * 2);
	memcpy(&mat_1[0][0], &mat[0][1], sizeof(mat[0][0]) * 2);
	memcpy(&mat_1[1][0], &mat[2][1], sizeof(mat[0][0]) * 2);
	memcpy(&mat_2[0][0], &mat[0][1], sizeof(mat[0][0]) * 2);
	memcpy(&mat_2[1][0], &mat[1][1], sizeof(mat[0][0]) * 2);
	return
		+(mat[0][0] * hf_mat2f_determinant(mat_0))
		-(mat[1][0] * hf_mat2f_determinant(mat_1))
		+(mat[2][0] * hf_mat2f_determinant(mat_2))
	;
}

float hf_mat3f_minor(HF_Mat3f mat, int i, int j) {
	HF_Mat2f mat_sub;
	int row = 0;
	for(int k = 0; k < 3; k++) {
		if(k == i) {
			continue;
		}
		int col = 0;
		for(int l = 0; l < 3; l++) {
			if(l == j) {
				continue;
			}
			mat_sub[row][col] = mat[k][l];
			col++;
		}
		row++;
	}
	return hf_mat2f_determinant(mat_sub);
}

void hf_mat3f_inverse(HF_Mat3f mat, HF_Mat3f out) {
	float det = hf_mat3f_determinant(mat);
	if(det == 0.0f) {
		return;
	}
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			out[j][i] = ((i + j) % 2 == 0 ? 1.f : -1.f) * hf_mat3f_minor(mat, i, j);
		}
	}
	hf_mat3f_multiply(out, 1.f / det, out);
}

void hf_mat3f_add(HF_Mat3f a, HF_Mat3f b, HF_Mat3f out) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat3f_multiply(HF_Mat3f mat, float scalar, HF_Mat3f out) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat3f_multiply_mat3x1f(HF_Mat3f a, HF_Mat3x1f b, HF_Mat3x1f out) {
	HF_Mat3x1f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 1; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 3);
}

void hf_mat3f_multiply_mat3x2f(HF_Mat3f a, HF_Mat3x2f b, HF_Mat3x2f out) {
	HF_Mat3x2f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 6);
}

void hf_mat3f_multiply_mat3f(HF_Mat3f a, HF_Mat3f b, HF_Mat3f out) {
	HF_Mat3f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 9);
}

void hf_mat3f_multiply_mat3x4f(HF_Mat3f a, HF_Mat3x4f b, HF_Mat3x4f out) {
	HF_Mat3x4f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 12);
}

void hf_mat3x4f_copy(HF_Mat3x4f mat, HF_Mat3x4f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 12);
}

void hf_mat3x4f_transpose(HF_Mat3x4f mat, HF_Mat4x3f out) {
	HF_Mat4x3f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 12);
}

void hf_mat3x4f_add(HF_Mat3x4f a, HF_Mat3x4f b, HF_Mat3x4f out) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat3x4f_multiply(HF_Mat3x4f mat, float scalar, HF_Mat3x4f out) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat3x4f_multiply_mat4x1f(HF_Mat3x4f a, HF_Mat4x1f b, HF_Mat3x1f out) {
	HF_Mat3x1f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 1; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 3);
}

void hf_mat3x4f_multiply_mat4x2f(HF_Mat3x4f a, HF_Mat4x2f b, HF_Mat3x2f out) {
	HF_Mat3x2f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 6);
}

void hf_mat3x4f_multiply_mat4x3f(HF_Mat3x4f a, HF_Mat4x3f b, HF_Mat3f out) {
	HF_Mat3f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 9);
}

void hf_mat3x4f_multiply_mat4f(HF_Mat3x4f a, HF_Mat4f b, HF_Mat3x4f out) {
	HF_Mat3x4f tmp;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 12);
}

void hf_mat4x1f_copy(HF_Mat4x1f mat, HF_Mat4x1f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 4);
}

void hf_mat4x1f_transpose(HF_Mat4x1f mat, HF_Mat1x4f out) {
	HF_Mat1x4f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 1; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat4x1f_add(HF_Mat4x1f a, HF_Mat4x1f b, HF_Mat4x1f out) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 1; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat4x1f_multiply(HF_Mat4x1f mat, float scalar, HF_Mat4x1f out) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 1; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat4x1f_multiply_mat1x2f(HF_Mat4x1f a, HF_Mat1x2f b, HF_Mat4x2f out) {
	HF_Mat4x2f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 8);
}

void hf_mat4x1f_multiply_mat1x3f(HF_Mat4x1f a, HF_Mat1x3f b, HF_Mat4x3f out) {
	HF_Mat4x3f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 12);
}

void hf_mat4x1f_multiply_mat1x4f(HF_Mat4x1f a, HF_Mat1x4f b, HF_Mat4f out) {
	HF_Mat4f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 16);
}

void hf_mat4x2f_copy(HF_Mat4x2f mat, HF_Mat4x2f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 8);
}

void hf_mat4x2f_transpose(HF_Mat4x2f mat, HF_Mat2x4f out) {
	HF_Mat2x4f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 8);
}

void hf_mat4x2f_add(HF_Mat4x2f a, HF_Mat4x2f b, HF_Mat4x2f out) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat4x2f_multiply(HF_Mat4x2f mat, float scalar, HF_Mat4x2f out) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat4x2f_multiply_mat2x1f(HF_Mat4x2f a, HF_Mat2x1f b, HF_Mat4x1f out) {
	HF_Mat4x1f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 1; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat4x2f_multiply_mat2f(HF_Mat4x2f a, HF_Mat2f b, HF_Mat4x2f out) {
	HF_Mat4x2f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 8);
}

void hf_mat4x2f_multiply_mat2x3f(HF_Mat4x2f a, HF_Mat2x3f b, HF_Mat4x3f out) {
	HF_Mat4x3f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 12);
}

void hf_mat4x2f_multiply_mat2x4f(HF_Mat4x2f a, HF_Mat2x4f b, HF_Mat4f out) {
	HF_Mat4f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 16);
}

void hf_mat4x3f_copy(HF_Mat4x3f mat, HF_Mat4x3f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 12);
}

void hf_mat4x3f_transpose(HF_Mat4x3f mat, HF_Mat3x4f out) {
	HF_Mat3x4f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 12);
}

void hf_mat4x3f_add(HF_Mat4x3f a, HF_Mat4x3f b, HF_Mat4x3f out) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat4x3f_multiply(HF_Mat4x3f mat, float scalar, HF_Mat4x3f out) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat4x3f_multiply_mat3x1f(HF_Mat4x3f a, HF_Mat3x1f b, HF_Mat4x1f out) {
	HF_Mat4x1f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 1; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat4x3f_multiply_mat3x2f(HF_Mat4x3f a, HF_Mat3x2f b, HF_Mat4x2f out) {
	HF_Mat4x2f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 8);
}

void hf_mat4x3f_multiply_mat3f(HF_Mat4x3f a, HF_Mat3f b, HF_Mat4x3f out) {
	HF_Mat4x3f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 12);
}

void hf_mat4x3f_multiply_mat3x4f(HF_Mat4x3f a, HF_Mat3x4f b, HF_Mat4f out) {
	HF_Mat4f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 16);
}

void hf_mat4f_copy(HF_Mat4f mat, HF_Mat4f out) {
	memcpy(out, mat, sizeof(out[0][0]) * 16);
}

void hf_mat4f_identity(HF_Mat4f out) {
	float values[] = {
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
	memcpy(out, values, sizeof(out[0][0]) * 16);
}

void hf_mat4f_transpose(HF_Mat4f mat, HF_Mat4f out) {
	HF_Mat4f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			tmp[i][j] = mat[j][i];
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 16);
}

float hf_mat4f_determinant(HF_Mat4f mat) {
	HF_Mat3f mat_0, mat_1, mat_2, mat_3;
	memcpy(&mat_0[0][0], &mat[1][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_0[1][0], &mat[2][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_0[2][0], &mat[3][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_1[0][0], &mat[0][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_1[1][0], &mat[2][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_1[2][0], &mat[3][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_2[0][0], &mat[0][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_2[1][0], &mat[1][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_2[2][0], &mat[3][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_3[0][0], &mat[0][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_3[1][0], &mat[1][1], sizeof(mat[0][0]) * 3);
	memcpy(&mat_3[2][0], &mat[2][1], sizeof(mat[0][0]) * 3);
	return
		+(mat[0][0] * hf_mat3f_determinant(mat_0))
		-(mat[1][0] * hf_mat3f_determinant(mat_1))
		+(mat[2][0] * hf_mat3f_determinant(mat_2))
		-(mat[3][0] * hf_mat3f_determinant(mat_3))
	;
}

float hf_mat4f_minor(HF_Mat4f mat, int i, int j) {
	HF_Mat3f mat_sub;
	int row = 0;
	for(int k = 0; k < 4; k++) {
		if(k == i) {
			continue;
		}
		int col = 0;
		for(int l = 0; l < 4; l++) {
			if(l == j) {
				continue;
			}
			mat_sub[row][col] = mat[k][l];
			col++;
		}
		row++;
	}
	return hf_mat3f_determinant(mat_sub);
}

void hf_mat4f_inverse(HF_Mat4f mat, HF_Mat4f out) {
	float det = hf_mat4f_determinant(mat);
	if(det == 0.0f) {
		return;
	}
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			out[j][i] = ((i + j) % 2 == 0 ? 1.f : -1.f) * hf_mat4f_minor(mat, i, j);
		}
	}
	hf_mat4f_multiply(out, 1.f / det, out);
}

void hf_mat4f_add(HF_Mat4f a, HF_Mat4f b, HF_Mat4f out) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			out[i][j] = a[i][j] + b[i][j];
		}
	}
}

void hf_mat4f_multiply(HF_Mat4f mat, float scalar, HF_Mat4f out) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			out[i][j] = mat[i][j] * scalar;
		}
	}
}

void hf_mat4f_multiply_mat4x1f(HF_Mat4f a, HF_Mat4x1f b, HF_Mat4x1f out) {
	HF_Mat4x1f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 1; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 4);
}

void hf_mat4f_multiply_mat4x2f(HF_Mat4f a, HF_Mat4x2f b, HF_Mat4x2f out) {
	HF_Mat4x2f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 8);
}

void hf_mat4f_multiply_mat4x3f(HF_Mat4f a, HF_Mat4x3f b, HF_Mat4x3f out) {
	HF_Mat4x3f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 12);
}

void hf_mat4f_multiply_mat4f(HF_Mat4f a, HF_Mat4f b, HF_Mat4f out) {
	HF_Mat4f tmp;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a[i][k] * b[k][j];
			}
			tmp[i][j] = val;
		}
	}
	memcpy(out, tmp, sizeof(out[0][0]) * 16);
}
