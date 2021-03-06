#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <string>

class Complex {
private:
	double real, imaginary;

public:
	Complex(); // default constructor
	Complex(double r, double i); // parameterized constructor
	Complex(const Complex &other);
	~Complex(); // destructor
	
	// overloading operators
	Complex& operator=(const Complex &other);

	// accessor and mutators
	double GetReal() const; 
	void SetReal(double r);
	double GetImaginary() const; 
	void SetImaginary(double i);

	// METHODS
	double AbsoluteValue() const;
	double Magnitude() const;
	bool Equals(const Complex &other) const; 
	std::string ToString() const;
	Complex GetConjugate() const;
	Complex Multiply(const Complex &other) const;

};


#endif