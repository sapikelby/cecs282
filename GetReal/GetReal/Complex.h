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
	double GetReal(); 
	void SetReal(double r);
	double GetImaginary(); 
	void SetImaginary(double i);

	// METHODS
	double AbsoluteValue() const;
	// just checking if equals, not modifying actual Complex object passed in
	bool isEquals(const Complex &other) const; 
	std::string ToString() const;
	Complex Conjugate() const;
	Complex Multiply(const Complex &other) const;

};


#endif