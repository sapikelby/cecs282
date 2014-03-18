#include <iostream>
#include "Complex.h"

#include <sstream>
#include <string>

// constructors and destructors
Complex::Complex() : real(0), imaginary(0) {
	std::cout << "Default constructor: " << ToString() << std::endl;
}
Complex::Complex(double r, double i) :  real(r), imaginary(i) {
	std::cout << "Construct: " << ToString() << std::endl;
}
Complex::~Complex()
{
	std::cout << "Destruct: " << ToString() << std::endl;
}

// copies other's data onto *this object
// remember that when this happens, the new object created will not change
// "other" object when its data is changed
Complex::Complex(const Complex &other)  
{
	real = other.real;
	imaginary = other.imaginary;
	std::cout << "Copy construct: " << ToString() << std::endl;
}


// overloading 
Complex& Complex::operator=(const Complex &other)
{
	std::cout << "Operator = " << ToString();
	real = other.real;
	imaginary = other.imaginary;
	
	std::cout << " ==> " << ToString() << std::endl;
	return *this;
}

// accessor and mutators
double Complex::GetReal() const {
	return real;
}

void Complex::SetReal(double r) {
	std::cout << "Mutate " << ToString() << " to ";
	real = r;
	std::cout << ToString() << std::endl;
}

double Complex::GetImaginary() const {
	return imaginary;
}

void Complex::SetImaginary(double i) {
	std::cout << "Mutate " << ToString() << " to ";
	imaginary = i;
	std:: cout << ToString() << std::endl;
}

// methods
// same as abs val... added for specs purposes
double Complex::Magnitude() const {
	std::cout << "Absolute value" << std::endl;
	return (sqrt(real * real + imaginary * imaginary));
}

double Complex::AbsoluteValue() const {
	std::cout << "Absolute value" << std::endl;
	return (sqrt(real * real + imaginary * imaginary));
}
bool Complex::Equals(const Complex &other) const {
	return (real == other.real && imaginary == other.imaginary) ? true : false;
	
}
std::string Complex::ToString() const {
	std::string sign = (imaginary >= 0) ? "+" : "";
	std::ostringstream format; 
	format << real << sign << imaginary << "i";
	return format.str();
}
Complex Complex::GetConjugate() const {
	std::cout << "Conjugate" << std::endl;
	return Complex(real, -1 * imaginary);
}

Complex Complex::Multiply(const Complex &other) const {
	std::cout << "Multiply" << std::endl;
	int a = real * other.real - imaginary * other.imaginary;
	int b = real * other.imaginary + imaginary * other.real;
	return Complex(a, b);
}