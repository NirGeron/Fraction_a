/**
 *
 * @author Nir Geron
 * id 315874925
 * 
 */

#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"

using namespace std;
using namespace ariel;

//initialize the numerator to 0 and the denominator to 1.
Fraction::Fraction() : numerator(0), denominator(1) {}
Fraction::Fraction(float number){
//The prec constant is used to specify the precision of the conversion.
const int prec = 1000; 

this->numerator = static_cast<int>(number * prec); 
this->denominator = prec;
}

Fraction::Fraction(int num, int den) {
    // checks if the denominator is negative and if it is, 
    // it flips the signs of both the numerator and denominator.
    if (den < 0) {
        num = -num;
        den = -den;
    }
    if (den == 0) {
        throw std::invalid_argument("the denominat cant be 0");
    }
    this->denominator = den;
    this->numerator = num;
}

Fraction Fraction::reduce() {
    int gcd = Fraction::gcd(numerator, denominator);
    denominator /= gcd;
    numerator /= gcd;
    return *this;
}

int Fraction::gcd(int num, int den) {
    // This method reduces the fraction to its simplest form by dividing both the numerator
    // and the denominator by their greatest common divisor (GCD). 
    return den == 0 ? num : gcd(den, num % den);
}

Fraction Fraction::operator+(const Fraction& number) const {
    int num = numerator * number.denominator + denominator * number.numerator;
    int den = denominator * number.denominator;
    return Fraction(num, den).reduce();
}

Fraction ariel::operator+( const Fraction& fconst ,float num){
   Fraction t= Fraction(num);
return (fconst+t).reduce();
}

Fraction ariel::operator+(float num,const Fraction& fconst ){
   Fraction t= Fraction(num);
    return (fconst+t).reduce();
}

Fraction Fraction::operator-(const Fraction& number) const {
    int num = numerator * number.denominator - denominator * number.numerator;
    int denom = denominator * number.denominator;
    return Fraction(num, denom).reduce();
}

Fraction ariel::operator-(const Fraction& number, float num) {
    Fraction t= Fraction(num);
    return (number-t).reduce();
}

Fraction ariel::operator-(float num,const Fraction& number)  {
    Fraction t = Fraction(num);
    return (t-number).reduce();
}

Fraction Fraction::operator*(const Fraction& number) const {
    int num = numerator * number.numerator;
    int den = denominator * number.denominator;
    return Fraction(num, den).reduce();
}

Fraction ariel::operator*(float num,const Fraction& franc){
    Fraction t= Fraction(num);
    return (franc*t).reduce();
}

Fraction ariel::operator*(const Fraction& franc,float num){
    Fraction t= Fraction(num);
    return (franc*t).reduce();
}

Fraction Fraction::operator/(const Fraction& number) const {
    int num = numerator * number.denominator;
    int den = denominator * number.numerator;
    return Fraction(num, den).reduce();
}

Fraction ariel::operator/(const Fraction& frac, float num) {
    Fraction num_fraction = Fraction(num);
    return (frac/num_fraction).reduce();
}

Fraction ariel::operator/( float num,const Fraction& frac) {
    Fraction num_fraction = Fraction(num);
    return (num_fraction/frac).reduce();
}

Fraction Fraction::operator++() {
    numerator += denominator;
    return (*this).reduce();
}

Fraction Fraction::operator++(int) {
    Fraction t(*this);
    ++(*this);
    return t.reduce();
}

Fraction Fraction::operator--() {
    numerator -= denominator;
    return (*this).reduce();
}

Fraction Fraction::operator--(int) {
    Fraction t(*this);
    --(*this);
    return t.reduce();
}

bool Fraction::operator>(const float value)  {
    Fraction number=Fraction(value);
    return (numerator*number.denominator > number.numerator* denominator);
}

bool Fraction::operator>(const Fraction& number) {
    return (numerator*number.denominator > number.numerator* denominator);
}

bool Fraction::operator>=(const Fraction& number) {
    return (numerator*number.denominator >= number.numerator* denominator);
}

bool Fraction::operator>=(const float value)  {
    return ((numerator/denominator) >= value);
}

bool ariel::operator>(float number,const Fraction& frac){
    Fraction t=Fraction(number);
    return (t>frac);
}

bool ariel::operator>=(float number,const Fraction& frac){
    Fraction t=Fraction(number);
    return (t>=frac);
}

bool Fraction::operator<(const float value)  {
    Fraction number=Fraction(value);
    return (numerator*number.denominator < number.numerator* denominator);
}

bool Fraction::operator<(const Fraction& number) {
    return (numerator*number.denominator < number.numerator* denominator);
}

bool Fraction::operator<=(const Fraction& number) {
    return (numerator*number.denominator <= number.numerator* denominator);
}

bool Fraction::operator<=(const float value)  {
    return ((numerator/denominator) <= value);
}

bool ariel::operator<(float number,const Fraction& frac){
    Fraction t=Fraction(number);
    return (t<frac);
}

bool ariel::operator<=(float number,const Fraction& frac){
    Fraction t=Fraction(number);
    return (t<=frac);
}

bool Fraction::operator==(const Fraction& number) const{
    return (numerator*number.denominator <= number.numerator* denominator);
}

bool Fraction::operator==(float number ) const{
    Fraction t=Fraction(number);
    return ( (numerator*t.denominator) == (t.numerator*denominator));}