#pragma once
#include <iostream>

using namespace std;

struct Fraction
{
    int tu, mau;
};

struct ComplexNumbersFraction
{
    Fraction thuc, ao;
};


struct ComplexNumbers
{
    double thuc, ao;
};

istream& operator>>(istream& i, struct ComplexNumbers& x);
ostream& operator<<(ostream& o, struct ComplexNumbers x);
struct ComplexNumbers operator+(struct ComplexNumbers x, struct ComplexNumbers y);
struct ComplexNumbers operator+(struct ComplexNumbers x, double y);
struct ComplexNumbers operator+(double y, struct ComplexNumbers x);
struct ComplexNumbers operator-(struct ComplexNumbers x, struct ComplexNumbers y);
struct ComplexNumbers operator-(struct ComplexNumbers x);
struct ComplexNumbers operator*(struct ComplexNumbers x, struct ComplexNumbers y);
struct ComplexNumbersFraction operator/(struct ComplexNumbers x, struct ComplexNumbers y);

istream& operator>>(istream& i, struct ComplexNumbersFraction& x);
ostream& operator<<(ostream& o, struct ComplexNumbersFraction x);
struct ComplexNumbersFraction operator+(struct ComplexNumbersFraction x, struct ComplexNumbersFraction y);
struct ComplexNumbersFraction operator+(struct ComplexNumbersFraction x, double y);
struct ComplexNumbersFraction operator+(struct ComplexNumbersFraction x, struct Fraction y);
struct ComplexNumbersFraction operator+(double y, struct ComplexNumbersFraction x);
struct ComplexNumbersFraction operator-(struct ComplexNumbersFraction x, struct ComplexNumbersFraction y);
struct ComplexNumbersFraction operator-(struct ComplexNumbersFraction x);
struct ComplexNumbersFraction operator*(struct ComplexNumbersFraction x, struct ComplexNumbersFraction y);
struct ComplexNumbersFraction operator/(struct ComplexNumbersFraction x, struct ComplexNumbersFraction y);

