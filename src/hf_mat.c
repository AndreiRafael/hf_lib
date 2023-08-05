#include "../include/hf_mat.h"

HF_Mat2f hf_mat2f_identity(void) {
	return (HF_Mat2f) {
		.values = {
			{ 1.f, 0.f },
			{ 0.f, 1.f },
		}
	};
}

HF_Mat2f hf_mat2f_multiply(HF_Mat2f mat, float scalar) {
	HF_Mat2f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			out_mat.values[i][j] = mat.values[i][j] * scalar;
		}
	}
	return out_mat;
}

HF_Mat2f hf_mat2f_multiply_mat2f(HF_Mat2f a, HF_Mat2f b) {
	HF_Mat2f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat2x3f hf_mat2f_multiply_mat2x3f(HF_Mat2f a, HF_Mat2x3f b) {
	HF_Mat2x3f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat2x4f hf_mat2f_multiply_mat2x4f(HF_Mat2f a, HF_Mat2x4f b) {
	HF_Mat2x4f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat2x3f hf_mat2x3f_multiply(HF_Mat2x3f mat, float scalar) {
	HF_Mat2x3f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			out_mat.values[i][j] = mat.values[i][j] * scalar;
		}
	}
	return out_mat;
}

HF_Mat2f hf_mat2x3f_multiply_mat3x2f(HF_Mat2x3f a, HF_Mat3x2f b) {
	HF_Mat2f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat2x3f hf_mat2x3f_multiply_mat3f(HF_Mat2x3f a, HF_Mat3f b) {
	HF_Mat2x3f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat2x4f hf_mat2x3f_multiply_mat3x4f(HF_Mat2x3f a, HF_Mat3x4f b) {
	HF_Mat2x4f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat2x4f hf_mat2x4f_multiply(HF_Mat2x4f mat, float scalar) {
	HF_Mat2x4f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			out_mat.values[i][j] = mat.values[i][j] * scalar;
		}
	}
	return out_mat;
}

HF_Mat2f hf_mat2x4f_multiply_mat4x2f(HF_Mat2x4f a, HF_Mat4x2f b) {
	HF_Mat2f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat2x3f hf_mat2x4f_multiply_mat4x3f(HF_Mat2x4f a, HF_Mat4x3f b) {
	HF_Mat2x3f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat2x4f hf_mat2x4f_multiply_mat4f(HF_Mat2x4f a, HF_Mat4f b) {
	HF_Mat2x4f out_mat;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 2; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat3x2f hf_mat3x2f_multiply(HF_Mat3x2f mat, float scalar) {
	HF_Mat3x2f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			out_mat.values[i][j] = mat.values[i][j] * scalar;
		}
	}
	return out_mat;
}

HF_Mat3x2f hf_mat3x2f_multiply_mat2f(HF_Mat3x2f a, HF_Mat2f b) {
	HF_Mat3x2f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat3f hf_mat3x2f_multiply_mat2x3f(HF_Mat3x2f a, HF_Mat2x3f b) {
	HF_Mat3f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat3x4f hf_mat3x2f_multiply_mat2x4f(HF_Mat3x2f a, HF_Mat2x4f b) {
	HF_Mat3x4f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat3f hf_mat3f_identity(void) {
	return (HF_Mat3f) {
		.values = {
			{ 1.f, 0.f, 0.f },
			{ 0.f, 1.f, 0.f },
			{ 0.f, 0.f, 1.f },
		}
	};
}

HF_Mat3f hf_mat3f_multiply(HF_Mat3f mat, float scalar) {
	HF_Mat3f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			out_mat.values[i][j] = mat.values[i][j] * scalar;
		}
	}
	return out_mat;
}

HF_Mat3x2f hf_mat3f_multiply_mat3x2f(HF_Mat3f a, HF_Mat3x2f b) {
	HF_Mat3x2f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat3f hf_mat3f_multiply_mat3f(HF_Mat3f a, HF_Mat3f b) {
	HF_Mat3f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat3x4f hf_mat3f_multiply_mat3x4f(HF_Mat3f a, HF_Mat3x4f b) {
	HF_Mat3x4f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat3x4f hf_mat3x4f_multiply(HF_Mat3x4f mat, float scalar) {
	HF_Mat3x4f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			out_mat.values[i][j] = mat.values[i][j] * scalar;
		}
	}
	return out_mat;
}

HF_Mat3x2f hf_mat3x4f_multiply_mat4x2f(HF_Mat3x4f a, HF_Mat4x2f b) {
	HF_Mat3x2f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat3f hf_mat3x4f_multiply_mat4x3f(HF_Mat3x4f a, HF_Mat4x3f b) {
	HF_Mat3f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat3x4f hf_mat3x4f_multiply_mat4f(HF_Mat3x4f a, HF_Mat4f b) {
	HF_Mat3x4f out_mat;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 3; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat4x2f hf_mat4x2f_multiply(HF_Mat4x2f mat, float scalar) {
	HF_Mat4x2f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			out_mat.values[i][j] = mat.values[i][j] * scalar;
		}
	}
	return out_mat;
}

HF_Mat4x2f hf_mat4x2f_multiply_mat2f(HF_Mat4x2f a, HF_Mat2f b) {
	HF_Mat4x2f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat4x3f hf_mat4x2f_multiply_mat2x3f(HF_Mat4x2f a, HF_Mat2x3f b) {
	HF_Mat4x3f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat4f hf_mat4x2f_multiply_mat2x4f(HF_Mat4x2f a, HF_Mat2x4f b) {
	HF_Mat4f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat4x3f hf_mat4x3f_multiply(HF_Mat4x3f mat, float scalar) {
	HF_Mat4x3f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			out_mat.values[i][j] = mat.values[i][j] * scalar;
		}
	}
	return out_mat;
}

HF_Mat4x2f hf_mat4x3f_multiply_mat3x2f(HF_Mat4x3f a, HF_Mat3x2f b) {
	HF_Mat4x2f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat4x3f hf_mat4x3f_multiply_mat3f(HF_Mat4x3f a, HF_Mat3f b) {
	HF_Mat4x3f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat4f hf_mat4x3f_multiply_mat3x4f(HF_Mat4x3f a, HF_Mat3x4f b) {
	HF_Mat4f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat4f hf_mat4f_identity(void) {
	return (HF_Mat4f) {
		.values = {
			{ 1.f, 0.f, 0.f, 0.f },
			{ 0.f, 1.f, 0.f, 0.f },
			{ 0.f, 0.f, 1.f, 0.f },
			{ 0.f, 0.f, 0.f, 1.f },
		}
	};
}

HF_Mat4f hf_mat4f_multiply(HF_Mat4f mat, float scalar) {
	HF_Mat4f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			out_mat.values[i][j] = mat.values[i][j] * scalar;
		}
	}
	return out_mat;
}

HF_Mat4x2f hf_mat4f_multiply_mat4x2f(HF_Mat4f a, HF_Mat4x2f b) {
	HF_Mat4x2f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat4x3f hf_mat4f_multiply_mat4x3f(HF_Mat4f a, HF_Mat4x3f b) {
	HF_Mat4x3f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

HF_Mat4f hf_mat4f_multiply_mat4f(HF_Mat4f a, HF_Mat4f b) {
	HF_Mat4f out_mat;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			float val = 0.f;
			for(int k = 0; k < 4; k++) {
				val += a.values[i][k] * b.values[k][j];
			}
			out_mat.values[i][j] = val;
		}
	}
	return out_mat;
}

