// ALOHA spenso expression: 1.00000000000000𝑖*(OM_1*spenso::g(spenso::mink(4,1),spenso::mink(4,2))*spenso::g(spenso::mink(4,1),spenso::mink(4,spynso3::I3))*Scalar(3)*spenso_python::Vector(2,spenso::mink(4,2))*spenso_python::P(1,spenso::mink(4,spynso3::I2))*spenso_python::P(1,spenso::mink(4,spynso3::I3))-spenso::g(spenso::mink(4,1),spenso::mink(4,2))*spenso::g(spenso::mink(4,1),spenso::mink(4,spynso3::I2))*Scalar(3)*spenso_python::Vector(2,spenso::mink(4,2)))
// ALOHA spenso parameters: [spenso_python::Vector(2,spenso::cind(0)), spenso_python::Vector(2,spenso::cind(1)), spenso_python::Vector(2,spenso::cind(2)), spenso_python::Vector(2,spenso::cind(3)), Scalar(3), spenso_python::P(1,spenso::cind(0)), spenso_python::P(1,spenso::cind(1)), spenso_python::P(1,spenso::cind(2)), spenso_python::P(1,spenso::cind(3)), OM_1]
// Auto-generated with Symbolica 1.4.0
// Default build instructions: g++ -shared -O3 -fPIC -ffast-math -funsafe-math-optimizations -march=native VVS1_1.cpp

#include <iostream>
#include <cmath>

#include <complex>
typedef std::complex<double> Number;
extern "C" unsigned long VVS1_1_complexf64_get_buffer_len()
{
	return 20;
}


template<typename T>
void VVS1_1_complexf64_gen(T* params, T* Z, T* out) {
	Z[12] = params[0]*T(-1);
	Z[13] = params[1]*T(-1);
	Z[14] = params[6]*Z[13];
	Z[15] = params[2]*T(-1);
	Z[16] = params[7]*Z[15];
	Z[17] = params[3]*T(-1);
	Z[18] = params[8]*Z[17];
	Z[19] = params[0]*params[5];
	Z[14] = Z[14]+Z[16]+Z[18]+Z[19];
	Z[14] = params[9]*Z[14];
	Z[16] = params[5]*Z[14];
	Z[12] = Z[12]+Z[16];
	Z[12] = params[4]*Z[12];
	Z[12] = T(0, 1)*Z[12];
	Z[16] = params[6]*Z[14];
	Z[13] = Z[13]+Z[16];
	Z[13] = params[4]*Z[13];
	Z[13] = T(0, 1)*Z[13];
	Z[16] = params[7]*Z[14];
	Z[15] = Z[15]+Z[16];
	Z[15] = params[4]*Z[15];
	Z[15] = T(0, 1)*Z[15];
	Z[14] = params[8]*Z[14];
	Z[14] = Z[17]+Z[14];
	Z[14] = params[4]*Z[14];
	Z[14] = T(0, 1)*Z[14];
	out[0] = Z[12];
	out[1] = Z[13];
	out[2] = Z[15];
	out[3] = Z[14];
	return;
}

extern "C" {
	void VVS1_1_complexf64(std::complex<double> *params, std::complex<double> *buffer, std::complex<double> *out) {
		VVS1_1_complexf64_gen(params, buffer, out);
		return;
	}
}

 void VVS1_1(std::complex<double> V2[], std::complex<double> S3[], std::complex<double> COUP, double M1, double W1,std::complex<double>  V1[])
{
static std::complex<double> cI = std::complex<double>(0.,1.);
 double  OM1;
 double  P1[4];
 std::complex<double>  TMP0;
 std::complex<double>  denom;
    OM1 = 0.;
    if (M1 != 0.)
 OM1=1./(M1*M1);
    V1[0] = +V2[0]+S3[0];
    V1[1] = +V2[1]+S3[1];
P1[0] = -V1[0].real();
P1[1] = -V1[1].real();
P1[2] = -V1[1].imag();
P1[3] = -V1[0].imag();
    std::complex<double> spenso_params[10];
    std::complex<double> spenso_out[4];
    std::complex<double> spenso_buffer[20];
    spenso_params[0] = V2[2];
    spenso_params[1] = V2[3];
    spenso_params[2] = V2[4];
    spenso_params[3] = V2[5];
    spenso_params[4] = S3[2];
    spenso_params[5] = P1[0];
    spenso_params[6] = P1[1];
    spenso_params[7] = P1[2];
    spenso_params[8] = P1[3];
    spenso_params[9] = OM1;
    VVS1_1_complexf64(spenso_params, spenso_buffer, spenso_out);
    denom = COUP/((P1[0]*P1[0])-(P1[1]*P1[1])-(P1[2]*P1[2])-(P1[3]*P1[3]) - M1 * (M1 -cI* W1));
    V1[2]= denom*spenso_out[0];
    V1[3]= denom*spenso_out[1];
    V1[4]= denom*spenso_out[2];
    V1[5]= denom*spenso_out[3];
}
