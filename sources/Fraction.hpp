#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
namespace ariel{

class Fraction {
private:
    static int gcd(int number, int denom);
    int numerator;
    int denominator;

public:
    Fraction operator+(const Fraction& number) const;
    friend Fraction operator+( const Fraction& fracconst ,float number);
    friend Fraction operator+( float num,const Fraction& fracconst );
    
    Fraction();
    Fraction(int number, int denom = 1);
    Fraction(float number);

    Fraction operator-(const Fraction& number) const;
    friend Fraction operator-( const Fraction& fracconst ,float number);
    friend Fraction operator-( float number,const Fraction& fracconst );
    friend Fraction operator*(float number, const Fraction& frac);
    Fraction operator*(const Fraction& number) const;
    friend Fraction operator*( const Fraction& frac,float number );
    friend Fraction operator/(const Fraction& frac, float number);
    Fraction operator/(const Fraction& number) const;
    friend Fraction operator/(float number,const Fraction& frac);
    Fraction operator--(int);
    Fraction operator--();
    Fraction operator++(int);
    Fraction operator++();
    bool operator>(const Fraction& number) ;
    bool operator>(const float value) ;
    bool operator>=(const Fraction& number) ;
    bool operator>=(const float value) ;
    friend bool operator>(float number,const Fraction& frac);
    friend bool operator>=(float number,const Fraction& frac);
    bool operator<(const float value) ;
    bool operator<(const Fraction& number) ;
    bool operator<=(const float value);
    bool operator<=(const Fraction& number) ;
    friend bool operator<(float number,const Fraction& frac);
    friend bool operator<=(float number,const Fraction& frac);
    bool operator==(float number) const;
    bool operator==(const Fraction& number) const;
    
    Fraction reduce();
        friend std::ostream &operator<<(std::ostream& output, const Fraction& franc){
        output << franc.numerator << "/" << franc.denominator;
        return output;}
    friend std::istream &operator>>(std::istream& output,  Fraction& franc){
       char t='a';
        output >> franc.numerator >> t >> franc.denominator;
        return output;
    }
};
}

#endif 