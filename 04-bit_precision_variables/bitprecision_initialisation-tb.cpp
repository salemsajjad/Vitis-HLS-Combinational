#include "bitprecision_initialisation-tb.h"
#include <iostream>


int main() {
	int status = 0;


	ap_int<41> a1;
	ap_int<41> a2;
	ap_int<41> a3;
	ap_int<41> a4;

	ap_int< 763 > b1;
	ap_int< 763 > b2;
	ap_int< 763 > b3;

	bitprecision_initialisation(a1, a2, a3, a4, b1, b2, b3);

	std::cout << " a1 = " << a1 << std::endl;
	std::cout << " a2 = " << a2 << std::endl;
	std::cout << " a3 = " << a3 << std::endl;
	std::cout << " a4 = " << a4 << std::endl;


	std::cout << " b1 = " << b1 << std::endl;
	std::cout << " b2 = " << b2 << std::endl;
	std::cout << " b3 = " << b3 << std::endl;


	std::cout << " b1 = " << std::oct << b1 << std::endl;
	std::cout << " b1 = " << std::dec << b1 << std::endl;
	std::cout << " b1 = " << std::hex << b1 << std::endl;


	return status;

}
