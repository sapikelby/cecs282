#include <iostream>
#include "Complex.h"

#include <sstream>
#include <string>
Complex::Complex() : real(0), imaginary(0) {
	std::cout << "Default constructor " << ToString();
}
Complex::Complex(double r, double i) :  real(r), imaginary(i) {
	std::cout << "Imaginary number: " << ToString();
}


// accessor and mutators
double Complex::GetReal() {
	return real;
}

void Complex::SetReal(double r) {
	real = r;
}

double Complex::GetImaginary() {
	return imaginary;
}

void Complex::SetImaginary(double i) {
	imaginary = i;
}

// methods
double Complex::AbsoluteValue() const {
	return (sqrt(real * real + imaginary * imaginary));
}
bool Complex::isEquals(const Complex &other) const {
	return (real == other.real && imaginary == other.imaginary) ? true : false;
	
}
std::string Complex::ToString() const {
	std::string sign = (imaginary > 0) ? "+" : "-";
	std::ostringstream format; 
	format << real << " " << sign << " " << imaginary << "i";
	return format.str();
}
Complex Complex::Conjugate() const {
	//double iTemp; 
	//iTemp = imaginary;
	//Complex conjugate; 
	Complex conjugate = Complex(real, -imaginary);
	return conjugate;
}
Complex Complex::Multiply(const Complex &other) const {
	int a = 0; 
	int b = 0;
	a = real * other.real - imaginary * other.imaginary;
	b = real * other.real + imaginary * other.imaginary;
	return Complex(a, b);
}