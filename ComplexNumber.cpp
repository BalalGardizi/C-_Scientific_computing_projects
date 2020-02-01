#include "ComplexNumber.hpp"
#include <iostream>
#include <ostream>
#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero

ComplexNumber::ComplexNumber(){
mRealPart = 0.0;
mImaginaryPart = 0.0;
}

//constructor that sets complex number z =x+iy
ComplexNumber::ComplexNumber(double x, double y){
	mRealPart = x;
	mImaginaryPart = y;
	//GetRealPart(mRealPart);
}


//Method for computing the modulus of acomplex number
double ComplexNumber::CalculateModulus() const{
	return sqrt(mRealPart*mRealPart+
		mImaginaryPart*mImaginaryPart);
}



//Method for computing the argument of acomplex number
double ComplexNumber::CalculateArgument() const{
	return atan2(mImaginaryPart, mRealPart);
}




//Method for raising complex number to the power n
//using De Moivre’s theorem - first complex
//number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n)const{
	double modulus = CalculateModulus();
	double argument = CalculateArgument();
	double mod_of_result = pow(modulus, n);
	double arg_of_result = argument*n;
	double real_part = mod_of_result*cos(arg_of_result); 
	double imag_part = mod_of_result*sin(arg_of_result); 
	ComplexNumber z(real_part, imag_part);
	return z;
}

//overloading the = (assignment) operator
ComplexNumber& ComplexNumber::operator = (const ComplexNumber& z){
	mRealPart = z.mRealPart; 
	mImaginaryPart = z.mImaginaryPart;
	return *this;
}

//Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const{
	ComplexNumber w;
	w.mRealPart = -mRealPart; 
	w.mImaginaryPart = -mImaginaryPart;
	return w; 
}

/*(a+ib)*(c+id)= ac + aid + ibc + ibid = ac +aid + ibc -bd*/
//Overloading the binary + operator
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const{
	ComplexNumber w;
	w.mRealPart = mRealPart + z.mRealPart;
	w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
 	return w;
}


//Overloading the binary - operator
ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const{
	
	ComplexNumber w;
	w.mRealPart = mRealPart - z.mRealPart;
 	w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart; 
 return w;
}



/*(a+ib)*(c+id)= ac + aid + ibc + ibid = ac + aid + ibc -bd*/
/*(a+ib)*(c-id)= ac - ibid + ibc - aid = what about this form?*/

ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const{
	ComplexNumber w;
	w.mRealPart = mRealPart * z.mRealPart - mImaginaryPart*z.mImaginaryPart;
	w.mImaginaryPart = mRealPart*z.mImaginaryPart + mImaginaryPart*z.mRealPart;
	return w;
}

//Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output,const ComplexNumber& z)
 {
 //Formatas"(a+bi)"oras"(a-bi)"
output << "(" << z.mRealPart << " ";

if (z.mImaginaryPart >= 0.0)
 {
 output << "+ " << z.mImaginaryPart << "i)";
 }
 else
 {
 // z.mImaginaryPart < 0.0
 // Replace + with minus sign
 output << "- " << -z.mImaginaryPart << "i)";
 }
return output;}//warning here must return value

 
double ComplexNumber::GetRealPart () const { 
	return mRealPart;
}

double ComplexNumber::GetImaginaryPart () const {
	return mImaginaryPart;
}

double ImaginaryPart(const ComplexNumber& z){ //friend 
	return z.mImaginaryPart;
}

double RealPart(const ComplexNumber& z){
	return z.mRealPart;
}
ComplexNumber::ComplexNumber(const ComplexNumber& z){ //z is our object
	mRealPart = z.mRealPart; //overriden default constructer
	mImaginaryPart = z.mImaginaryPart;
}
//something that takes in double
ComplexNumber::ComplexNumber(double real){
	mRealPart = real;
	mImaginaryPart = 0;
}

ComplexNumber ComplexNumber::CalculateConjugate() const{ //
	ComplexNumber z(mRealPart,-mImaginaryPart);
	return z; //NB to specify type first - hence ComplexNumber
			 //NB to return a instance of class, return type
			//Nb to remember use of const, for not changing
}
void ComplexNumber::SetConjugate(){
	mImaginaryPart= -mImaginaryPart;
}
