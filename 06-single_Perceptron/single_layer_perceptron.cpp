#include "single_layer_perceptron.h"

float multiplication(ap_int<8> a, float b)
{
#pragma HLS INLINE off

	float temp = 0;
	temp = a * b;
	return temp;
}

float summation(float a, float b)
{
#pragma HLS INLINE off

	float temp = 0;
	temp = a + b;
	return temp;

}

void single_layer_perceptron (
         ap_int<8> x1,
         ap_int<8> x2,
         ap_int<8> x3,

         float w1,
         float w2,
         float w3,

         float b,

         bool &y)
{
#pragma HLS INTERFACE ap_ctrl_none port=return

#pragma HLS INTERFACE ap_none port=x1
#pragma HLS INTERFACE ap_none port=x2
#pragma HLS INTERFACE ap_none port=x3

#pragma HLS INTERFACE ap_none port=w1
#pragma HLS INTERFACE ap_none port=w2
#pragma HLS INTERFACE ap_none port=w3

#pragma HLS INTERFACE ap_none port=b

#pragma HLS INTERFACE ap_none port=y

	float m1 = multiplication(x1, w1);
	float m2 = multiplication(x2, w2);
	float m3 = multiplication(x3, w3);


	float s1 = summation(m1, m2);
	float s2 = summation(m3, b);
	float s  = summation(s1, s2);

	if(s >= 0)
		y = 1;
	else
		y = 0;


}
