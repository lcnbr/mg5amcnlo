// ALOHA spenso expression: -1.00000000000000𝑖*(-M_2*spenso::g(spenso::bis(4,51),spenso::bis(4,spynso3::I2))*spenso_python::Vector(3,spenso::mink(4,3))*spenso_python::gamma(spenso::bis(4,2),spenso::bis(4,1),spenso::mink(4,3))*spenso_python::C(spenso::bis(4,1),spenso::bis(4,52))*spenso_python::C(spenso::bis(4,2),spenso::bis(4,51))*spenso_python::Spinor(1,spenso::bis(4,52))+spenso_python::Vector(3,spenso::mink(4,3))*spenso_python::P(2,spenso::mink(4,spynso3::mu))*spenso_python::gamma(spenso::bis(4,2),spenso::bis(4,1),spenso::mink(4,3))*spenso_python::gamma(spenso::bis(4,51),spenso::bis(4,spynso3::I2),spenso::mink(4,spynso3::mu))*spenso_python::C(spenso::bis(4,1),spenso::bis(4,52))*spenso_python::C(spenso::bis(4,2),spenso::bis(4,51))*spenso_python::Spinor(1,spenso::bis(4,52)))
// ALOHA spenso parameters: [spenso_python::Spinor(1,spenso::cind(0)), spenso_python::Spinor(1,spenso::cind(1)), spenso_python::Spinor(1,spenso::cind(2)), spenso_python::Spinor(1,spenso::cind(3)), spenso_python::Vector(3,spenso::cind(0)), spenso_python::Vector(3,spenso::cind(1)), spenso_python::Vector(3,spenso::cind(2)), spenso_python::Vector(3,spenso::cind(3)), M_2, spenso_python::P(2,spenso::cind(0)), spenso_python::P(2,spenso::cind(1)), spenso_python::P(2,spenso::cind(2)), spenso_python::P(2,spenso::cind(3))]
// Auto-generated with Symbolica 1.4.0
// Default build instructions: g++ -shared -O3 -fPIC -ffast-math -funsafe-math-optimizations -march=native FFV1C1_1.cpp

#include <iostream>
#include <cmath>

#include <complex>
typedef std::complex<double> Number;
extern "C" unsigned long FFV1C1_1_complexf64_get_buffer_len()
{
	return 32;
}


template<typename T>
void FFV1C1_1_complexf64_gen(T* params, T* Z, T* out) {
	Z[16] = params[6]*T(-1);
	Z[17] = params[0]*Z[16];
	Z[18] = params[1]*params[7];
	Z[19] = params[2]*params[4];
	Z[20] = params[3]*params[5];
	Z[17] = Z[17]+Z[18]+Z[19]+Z[20];
	Z[21] = params[8]*T(-1);
	Z[22] = Z[17]*Z[21];
	Z[23] = params[0]*params[6]*T(0, -1);
	Z[19] = T(0, 1)*Z[19];
	Z[20] = T(0, -1)*Z[20];
	Z[18] = T(0, -1)*Z[18];
	Z[18] = Z[20]+Z[18];
	Z[18] = Z[19]+Z[18];
	Z[18] = Z[23]+Z[18];
	Z[19] = T(-1)*Z[18];
	Z[20] = T(-1)*Z[17];
	Z[23] = Z[19]+Z[20];
	Z[24] = params[11]*Z[23];
	Z[25] = params[3]*params[4];
	Z[26] = T(-1)*Z[25];
	Z[27] = params[2]*params[5];
	Z[28] = params[1]*params[6];
	Z[29] = params[0]*params[7];
	Z[28] = Z[27]+Z[28];
	Z[26] = Z[26]+Z[29];
	Z[30] = Z[28]+Z[26];
	Z[31] = T(0, -1)*Z[30];
	Z[29] = T(-1)*Z[29];
	Z[25] = Z[25]+Z[29];
	Z[28] = Z[28]+Z[25];
	Z[29] = Z[31]+Z[28];
	Z[29] = params[12]*Z[29];
	Z[22] = Z[22]+Z[24]+Z[29];
	Z[22] = T(0, -1)*Z[22];
	Z[16] = params[1]*Z[16];
	Z[24] = T(-1)*Z[27];
	Z[16] = Z[16]+Z[24];
	Z[24] = Z[26]+Z[16];
	Z[24] = Z[21]*Z[24];
	Z[26] = T(0, 1)*Z[30];
	Z[27] = Z[28]+Z[26];
	Z[29] = params[11]*Z[27];
	Z[20] = Z[18]+Z[20];
	Z[20] = params[12]*Z[20];
	Z[20] = Z[24]+Z[29]+Z[20];
	Z[20] = T(0, -1)*Z[20];
	Z[16] = Z[25]+Z[16];
	Z[16] = Z[21]*Z[16];
	Z[17] = Z[17]+Z[19];
	Z[17] = params[9]*Z[17];
	Z[19] = T(-1)*Z[28];
	Z[19] = Z[26]+Z[19];
	Z[19] = params[10]*Z[19];
	Z[16] = Z[16]+Z[17]+Z[19];
	Z[16] = T(0, -1)*Z[16];
	Z[17] = Z[21]*Z[18];
	Z[18] = params[9]*Z[27];
	Z[19] = params[10]*Z[23];
	Z[17] = Z[17]+Z[18]+Z[19];
	Z[17] = T(0, -1)*Z[17];
	out[0] = Z[22];
	out[1] = Z[20];
	out[2] = Z[16];
	out[3] = Z[17];
	return;
}

extern "C" {
	void FFV1C1_1_complexf64(std::complex<double> *params, std::complex<double> *buffer, std::complex<double> *out) {
		FFV1C1_1_complexf64_gen(params, buffer, out);
		return;
	}
}

 void FFV1C1_1(std::complex<double> F1[], std::complex<double> V3[], std::complex<double> COUP, double M2, double W2,std::complex<double>  F2[])
{
static std::complex<double> cI = std::complex<double>(0.,1.);
 double  P2[4];
 std::complex<double>  denom;
    F2[0] = +F1[0]+V3[0];
    F2[1] = +F1[1]+V3[1];
P2[0] = -F2[0].real();
P2[1] = -F2[1].real();
P2[2] = -F2[1].imag();
P2[3] = -F2[0].imag();
    std::complex<double> spenso_params[13];
    std::complex<double> spenso_out[4];
    std::complex<double> spenso_buffer[32];
    spenso_params[0] = F1[2];
    spenso_params[1] = F1[3];
    spenso_params[2] = F1[4];
    spenso_params[3] = F1[5];
    spenso_params[4] = V3[2];
    spenso_params[5] = V3[3];
    spenso_params[6] = V3[4];
    spenso_params[7] = V3[5];
    spenso_params[8] = M2;
    spenso_params[9] = P2[0];
    spenso_params[10] = P2[1];
    spenso_params[11] = P2[2];
    spenso_params[12] = P2[3];
    FFV1C1_1_complexf64(spenso_params, spenso_buffer, spenso_out);
    denom = COUP/((P2[0]*P2[0])-(P2[1]*P2[1])-(P2[2]*P2[2])-(P2[3]*P2[3]) - M2 * (M2 -cI* W2));
    F2[2]= denom*spenso_out[0];
    F2[3]= denom*spenso_out[1];
    F2[4]= denom*spenso_out[2];
    F2[5]= denom*spenso_out[3];
}
