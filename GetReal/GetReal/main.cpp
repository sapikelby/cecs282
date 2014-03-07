#include <iostream>
#include "Complex.h"

using namespace std;
int main(int argc, char* argv[])
{
	cout << "Lab 4: Get Real" << endl; 
	//int evens[4] = {2,4,6,8};
	//int *p = evens;
	Complex complex = Complex();
	complex.ToString();
	cout << "----" << endl;

	const Complex complex2 = Complex(5, 12);
	complex2.ToString();
	cout << "----" << endl;

	complex.SetReal(4);
	complex.SetImaginary(12);
	cout << "----" << endl;
	complex.ToString();
	cout << "----" << endl;
	//int *p2 = p + 3;
	//cout << *p2 << endl;
	system("pause"); 
}