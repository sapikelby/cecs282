#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <string>

class Complex {
private:
	double real, imaginary;

public:
	Complex(); // default constructor
	Complex(double r, double i); 

	// accessor and mutators
	double GetReal() const; 
	void SetReal(double r);
	double GetImaginary() const; 
	void SetImaginary(double i);

	// METHODS
	double AbsoluteValue() const;
	bool isEquals(const Complex &other) const; 
	std::string ToString() const;
	Complex Conjugate() const;
	Complex Multiply(const Complex &other) const;

};


#endif