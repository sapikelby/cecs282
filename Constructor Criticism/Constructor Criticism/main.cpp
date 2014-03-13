/***************************
*** Programmer: Kelby Sapien
*** Lab 4 CECS 282
*/
#include "Complex.h"
#include <iostream>

using namespace std;

void CompareComplex(Complex first, const Complex& second);

int main() {

   Complex c1(1.5, 2);
   Complex c2(-3, 4);
   Complex *cPtr;

   cout << endl;

   if (true) {
      Complex c3(c2);
      cPtr = new Complex(5, 5);
      cout << "The conjugate of " << c3.ToString() << " is " << 
       c3.GetConjugate().ToString() << endl;
   }

   cout << endl;
   Complex copy1 = c2;
   copy1.SetReal(10);
   Complex copy2(copy1);

   cout << endl;
   copy1 = c2;
   copy1 = c2.GetConjugate();

   cout << endl;
   Complex c3(-3, -4);
   CompareComplex(c3, copy1);
   cout << endl;
}

void CompareComplex(Complex first, const Complex& second) {
   cout << first.Equals(second) << endl;
}