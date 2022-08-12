/************************************************
Copyright (c) 2020, Mohammad Hosseinabady
All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. // Copyright (c) 2020, Mohammad Hosseinabady.
************************************************/

#include "arith_exp_dsp.h"



int mult_func(int a, int b) {
#pragma HLS INLINE off
	int r;
#pragma HLS BIND_OP variable=r op=mul impl=fabric       //Use Vitis-HLS 2021.2
	r =  a*b;
	return r;
}

int add_func(int a, int b) {
#pragma HLS INLINE off
	int r;
#pragma HLS BIND_OP variable=r op=add impl=dsp          //Use Vitis-HLS 2021.2

	r =  a+b;
	return r;
}


void arith_exp_dsp(int a, int b, int c, int *f ) {

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=a
#pragma HLS INTERFACE ap_none port=b
#pragma HLS INTERFACE ap_none port=c
#pragma HLS INTERFACE ap_none port=f


    int m1 = mult_func(a, b);
    int m2 = mult_func(a, c);
    int m3 = mult_func(c, b);
    int m4 = mult_func(m1, c);

    int a1 = add_func(m1, m2);
    int a2 = add_func(a1, m3);
    *f = add_func(a2, m4);

}


