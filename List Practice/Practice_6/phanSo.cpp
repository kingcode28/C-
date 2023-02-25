#include <iostream>
#include "phanSo.h"

using namespace std;

int main()
{
    PhanSo x, y;
    cin >> x >> y;
    cout << x + y << endl;
    cout << x - y << endl;
    cout << x * y << endl;
    cout << x / y << endl;
    return 0;
}

int UCLN(int a, int b) {
    if(a%b == 0) return b;
    else
        return UCLN(b, a%b);
}

void rutGon(struct PhanSo& p) {
    int uoc = UCLN(p.tu, p.mau);
    p.tu = p.tu / uoc;
    p.mau = p.mau / uoc;
}

istream& operator>>(istream& i, struct PhanSo& p) {
    cout << "Nhap tu: ";
    i >> p.tu;
    do
    {
        cout << "Nhap mau(khac 0): ";
        i >> p.mau;
    } while (p.mau == 0);
    rutGon(p);
    return i;
}

ostream& operator<<(ostream& o, struct PhanSo p) {
    if(p.tu == 0 || p.mau == 1) o << p.tu << endl;
    else {
        if(p.mau < 0) {
            p.tu = -p.tu;
            p.mau = -p.mau;
        }
        o << p.tu << "/" << p.mau << endl;
    }
    return o;
}

struct PhanSo operator+(struct PhanSo p, struct PhanSo q) {
    PhanSo tmp;
    tmp.tu = p.tu*q.mau + q.tu*p.mau;
    tmp.mau = p.mau * q.mau;
    rutGon(tmp);
    return tmp;
}

struct PhanSo operator+(struct PhanSo p, int a) {
    p.tu = p.tu + a*p.mau;
    rutGon(p);
    return p;
}

struct PhanSo operator+(int a, struct PhanSo p) {
    p.tu = p.tu + a*p.mau;
    rutGon(p);
    return p;
}

struct PhanSo operator-(struct PhanSo p, struct PhanSo q) {
    PhanSo tmp;
    tmp.tu = p.tu*q.mau - q.tu*p.mau;
    tmp.mau = p.mau * q.mau;
    rutGon(tmp);
    return tmp;
}

struct PhanSo operator-(struct PhanSo p, int a) {
    p.tu = p.tu - a*p.mau;
    rutGon(p);
    return p;
}

struct PhanSo operator-(int a, struct PhanSo p) {
    p.tu = a*p.mau - p.tu;
    rutGon(p);
    return p;
}

struct PhanSo operator-(struct PhanSo p) {
    p.tu = -p.tu;
    rutGon(p);
    return p;
}

struct PhanSo operator*(struct PhanSo p, struct PhanSo q) {
    PhanSo tmp;
    tmp.tu = p.tu * q.tu;
    tmp.mau = p.mau * q.mau;
    rutGon(tmp);
    return tmp;
}

struct PhanSo operator*(struct PhanSo p, int a) {
    p.tu = p.tu * a;
    rutGon(p);
    return p;
}

struct PhanSo operator*(int a, struct PhanSo p) {
    p.tu = a * p.tu;
    rutGon(p);
    return p;
}

struct PhanSo operator/(struct PhanSo p, struct PhanSo q) {
    PhanSo tmp;
    tmp.tu = p.tu * q.mau;
    tmp.mau = p.mau * q.tu;
    rutGon(tmp);
    return tmp;
}

struct PhanSo operator/(struct PhanSo p, int a) {
    p.mau = p.mau * a;
    rutGon(p);
    return p;
}

struct PhanSo operator/(int a, struct PhanSo p) {
    p.mau = p.mau * a;
    rutGon(p);
    return p;
}

