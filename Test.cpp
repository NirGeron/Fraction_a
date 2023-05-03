/**
 *
 * @author Nir Geron
 * id 315874925
 */

#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"

using namespace ariel;

TEST_CASE("Constructor with valid and invalid inputs"){
    CHECK_NOTHROW(Fraction(12,10));
    CHECK_NOTHROW(Fraction(14,8));
    CHECK_NOTHROW(Fraction(10,16));
    CHECK_THROWS(Fraction(4,0));
    CHECK_THROWS(Fraction(14,0));
    CHECK_THROWS(Fraction(18,0));
}

TEST_CASE("+sum op"){
    Fraction frac1=Fraction(1,2);
    Fraction frac2=Fraction(1,4);
    Fraction frac3=Fraction(-1,4);
    Fraction frac5=Fraction(-3,4);
    Fraction frac6=Fraction(-3,2);
    CHECK_EQ(frac1+frac2,Fraction(3,4));
    CHECK_EQ(frac1+frac3,Fraction(1,4));
    CHECK_EQ(frac2+frac5,Fraction(-1,2));
    CHECK_EQ(frac3+frac6,Fraction(-3,4));
}

TEST_CASE("-sub op"){
    Fraction frac1=Fraction(1,2);
    Fraction frac2=Fraction(1,4);
    Fraction frac3=Fraction(-1,4);
    Fraction frac4=Fraction(-1,2);
    CHECK_EQ(frac1-frac2,Fraction(1,4));
    CHECK_EQ(frac1-frac3,Fraction(3,4));
    CHECK_EQ(frac1-frac4,Fraction(1,1));
}

TEST_CASE("*mul op"){
    Fraction frac1=Fraction(1,2);
    Fraction frac2=Fraction(1,4);
    Fraction frac3=Fraction(-1,4);
    Fraction frac4=Fraction(-1,2);
    Fraction frac5=Fraction(-3,4);
    Fraction frac6=Fraction(-3,2);
    CHECK_EQ(frac1*frac2,Fraction(1,8));
    CHECK_EQ(frac1*frac3,Fraction(-1,8));
    CHECK_EQ(frac2*frac4,Fraction(-1,8));
    CHECK_EQ(frac5*frac6,Fraction(9,8));
}


TEST_CASE("= op"){
    Fraction frac1=Fraction(1,4);
    Fraction frac2=Fraction(3,12);
    CHECK_EQ(0.25,frac1);
    CHECK_EQ(0.2500,frac1);
    CHECK_EQ(frac1,frac2);
    CHECK_EQ(frac1,0.25);
}

TEST_CASE("+sum op"){
    Fraction frac1=Fraction(1,2);
    Fraction frac2=Fraction(1,4);
    CHECK_EQ(frac1-frac2,frac2);
    CHECK_EQ(frac1-0.25,frac2);
    CHECK_EQ(frac1-frac2,0.25);
    CHECK_EQ(frac2-frac1,-0.25);
}

TEST_CASE("+ op"){
    Fraction frac1=Fraction(2,4);
    Fraction frac2=Fraction(3,6);
    Fraction frac4=Fraction(14,12);
    CHECK_EQ(frac1+frac2,1);
    CHECK_EQ(frac4+frac2,frac1+Fraction(14,12));
    CHECK_EQ(frac1+frac2,1);
    CHECK_EQ(frac4+frac2,frac1+Fraction(14,12));
}

TEST_CASE("* op"){
    Fraction frac1=Fraction(2,4);
    Fraction frac2=Fraction(16,24);
    Fraction frac3 =Fraction(30,20);
    CHECK_EQ(0.5*frac1,0.25);
    CHECK_EQ(frac2*frac3,1);
}
TEST_CASE("/L op"){
    Fraction frac1=Fraction(2,4);
    Fraction frac2=Fraction(14,24);
    Fraction frac3=Fraction(16,34);
    Fraction frac4=Fraction(38,30);
    Fraction frac5=Fraction(2,6);
    Fraction frac6=Fraction(2,30);
    CHECK_EQ( (frac1 <= frac3),false);
    CHECK_EQ((frac1<0.4),false);
    CHECK_EQ((0.522<frac1),false);

    CHECK_EQ((frac2<frac5),false);
    CHECK_EQ((frac3<=frac6),false);
    CHECK_EQ((frac4<=frac2),false);
    CHECK_EQ((0.500<=frac1),true);
}

TEST_CASE("/G op"){
    Fraction frac1=Fraction(2,4);
    Fraction frac2=Fraction(14,24);
    Fraction frac3=Fraction(16,34);
    Fraction frac4=Fraction(38,30);
    Fraction frac5=Fraction(2,6);
    Fraction frac6=Fraction(2,30);
    CHECK_EQ( (frac1 >= frac3),true);
    CHECK_EQ((frac1>0.4),true);
    CHECK_EQ((0.522>frac1),true);

    CHECK_EQ((frac2>frac5),true);
    CHECK_EQ((frac3>=frac6),true);
    CHECK_EQ((frac4>=frac2),true);
    CHECK_EQ((0.500>=frac1),true);
}


