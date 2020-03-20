#include"tests.h"
#include "bigtests.h"
#include "ADTMatrix.h"
#include<iostream>
#include <assert.h>
#include <stdexcept>

using namespace std;

int main() {

	/*Matrix m(2, 2);
	m.modify(1, 1, 12);
	m.resize(3, 3);
	m.modify(2, 2, 20);
	std::cout << m.element(2, 2);*/
	
	testAll();
	testAllExtended();
	std::cout << "tests passed";
	std::cin.get();
	return 0;
}