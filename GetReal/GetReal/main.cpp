/***************************
*** Programmer: Kelby Sapien
*** Lab 3 CECS 282
*/
#include <iostream>
#include "Complex.h"

using namespace std;
int main(int argc, char* argv[]) {
	cout << "Lab 4: Get Real" << endl << endl; 
	
	Complex complex1 = Complex();
	cout << "Complex1: " << complex1.ToString() << endl;
	cout << "----" << endl;
	complex1.SetReal(4);
	complex1.SetImaginary(-12);
	
	cout << "Complex1 after calling setters: " << complex1.ToString() << endl;
	cout << "Real: " << complex1.GetReal() << endl;
	cout << "Imaginary: " << complex1.GetImaginary() << endl; 

	cout << "----" << endl;
	const Complex complex2 = Complex(5, -12);
	cout << "Complex2: " << complex2.ToString() << endl;
	cout << "Absolute value: " << complex2.AbsoluteValue() << endl;

	cout << "Answer: " << complex1.Multiply(complex2).ToString() << endl;

	system("pause"); 
}