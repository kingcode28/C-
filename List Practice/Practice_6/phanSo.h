#pragma once
#include <iostream>

using namespace std;

struct PhanSo
{
    int tu, mau;
};

istream& operator>>(istream& i, struct PhanSo& p);
ostream& operator<<(ostream& o, struct PhanSo p);
int UCLN(int a, int b);
void rutGon(struct PhanSo& p);
struct PhanSo operator+(struct PhanSo p, struct PhanSo q);
struct PhanSo operator+(struct PhanSo p, int a);
struct PhanSo operator+(int a, struct PhanSo p);
struct PhanSo operator-(struct PhanSo p, struct PhanSo q);
struct PhanSo operator-(struct PhanSo p, int a);
struct PhanSo operator-(int a, struct PhanSo p);
struct PhanSo operator-(struct PhanSo p);
struct PhanSo operator*(struct PhanSo p, struct PhanSo q);
struct PhanSo operator*(struct PhanSo p, int a);
struct PhanSo operator*(int a, struct PhanSo p);
struct PhanSo operator/(struct PhanSo p, struct PhanSo q);
struct PhanSo operator/(struct PhanSo p, int a);
struct PhanSo operator/(int a, struct PhanSo p);


