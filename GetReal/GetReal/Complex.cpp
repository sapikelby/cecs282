#include <iostream>
#include "Complex.h"

#include <sstream>
#include <string>
Complex::Complex() : real(0), imaginary(0) {
	std::cout << "Default constructor: " << std::endl;
}
Complex::Complex(double r, double i) :  real(r), imaginary(i) {
}

// accessor and mutators
double Complex::GetReal() const {
	return real;
}

void Complex::SetReal(double r) {
	real = r;
}

double Complex::GetImaginary() const {
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
	std::string sign = (imaginary >= 0) ? "+" : "";
	std::ostringstream format; 
	format << real << sign << imaginary << "i";
	return format.str();
}
Complex Complex::Conjugate() const {
	return Complex(real, -1 * imaginary);
}

Complex Complex::Multiply(const Complex &other) const {
	int a = real * other.real - imaginary * other.imaginary;
	int b = real * other.imaginary + imaginary * other.real;
	return Complex(a, b);
}