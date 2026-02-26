// Auto-generated with Symbolica 1.4.0
// Default build instructions: g++ -shared -O3 -fPIC -ffast-math -funsafe-math-optimizations -march=native test_expression.cpp

#include <iostream>
#include <cmath>

#include <complex>
typedef std::complex<double> Number;
extern "C" unsigned long f_complexf64_get_buffer_len()
{
	return 30;
}


template<typename T>
void f_complexf64_gen(T* params, T* Z, T* out) {
	Z[22] = params[0]*T(-1);
	Z[23] = params[1]*T(-1);
	Z[24] = params[5]*Z[23];
	Z[25] = params[2]*T(-1);
	Z[26] = params[6]*Z[25];
	Z[27] = params[3]*T(-1);
	Z[28] = params[7]*Z[27];
	Z[29] = params[0]*params[4];
	Z[24] = Z[24]+Z[26]+Z[28]+Z[29];
	Z[24] = params[16]*Z[24];
	Z[26] = params[4]*Z[24];
	Z[22] = Z[22]+Z[26];
	Z[22] = params[19]*Z[22];
	Z[22] = T(0, 1)*Z[22];
	Z[26] = params[5]*Z[24];
	Z[23] = Z[23]+Z[26];
	Z[23] = params[19]*Z[23];
	Z[23] = T(0, 1)*Z[23];
	Z[26] = params[6]*Z[24];
	Z[25] = Z[25]+Z[26];
	Z[25] = params[19]*Z[25];
	Z[25] = T(0, 1)*Z[25];
	Z[24] = params[7]*Z[24];
	Z[24] = Z[27]+Z[24];
	Z[24] = params[19]*Z[24];
	Z[24] = T(0, 1)*Z[24];
	out[0] = Z[22];
	out[1] = Z[23];
	out[2] = Z[25];
	out[3] = Z[24];
	return;
}

extern "C" {
	void f_complexf64(std::complex<double> *params, std::complex<double> *buffer, std::complex<double> *out) {
		f_complexf64_gen(params, buffer, out);
		return;
	}
}
