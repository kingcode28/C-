#include <iostream>
#include "complexNumbers.h"

using namespace std;

int main()
{
    ComplexNumbers s1, s3;
    ComplexNumbersFraction s2;
    cin >> s1;
    cin >> s3;
    cout << s1 / s3;
    return 0;
}

istream& operator>>(istream& i, struct ComplexNumbers& x)
{
    cout << "Nhap phan thuc: ";
    i >> x.thuc;
    cout << "Nhap phan ao: ";
    i >> x.ao;
    return i;
}

ostream& operator<<(ostream& o, struct ComplexNumbers x)
{
    if(x.thuc)
    {
        if(!x.ao) o << x.thuc << endl;
        else
            if(x.ao > 0) o << x.thuc << "+" << x.ao << "i" << endl;
            else o << x.thuc << x.ao << "i" << endl;
    }
    else
    {
        if(!x.ao) o << x.thuc << endl;
        else
            o << x.ao << "i" << endl;
    }
    return o;
}

struct ComplexNumbers operator+(struct ComplexNumbers x, struct ComplexNumbers y)
{
    ComplexNumbers tmp;
    tmp.thuc = x.thuc + y.thuc;
    tmp.ao = x.ao + y.ao;
    return tmp;
}

struct ComplexNumbers operator+(struct ComplexNumbers x, double y)
{
    x.thuc = x.thuc + y;
    return x;
}

struct ComplexNumbers operator+(double y, struct ComplexNumbers x)
{
    x.thuc = x.thuc + y;
    return x;
}

struct ComplexNumbers operator-(struct ComplexNumbers x, struct ComplexNumbers y)
{
    ComplexNumbers tmp;
    tmp.thuc = x.thuc - y.thuc;
    tmp.ao = x.ao - y.ao;
    return tmp;
}

struct ComplexNumbers operator-(struct ComplexNumbers x)
{
    x.thuc = -x.thuc;
    x.ao = -x.ao;
    return x;
}

struct ComplexNumbers operator*(struct ComplexNumbers x, struct ComplexNumbers y)
{
    ComplexNumbers tmp;
    tmp.thuc = (x.thuc * y.thuc) - (x.ao * y.ao);
    tmp.ao = (x.thuc * y.ao) + (x.ao * y.thuc);
    return tmp;
}

istream& operator>>(istream& i, struct ComplexNumbersFraction& x)
{
    cout << "Nhap tu phan thuc: ";
    i >> x.thuc.tu;
    do
    {
        cout << "Nhap mau phan thuc(khac 0): ";
        i >> x.thuc.mau;
    } while (!x.thuc.mau);
    
    cout << "Nhap tu phan ao: ";
    i >> x.ao.tu;
    do
    {
        cout << "Nhap mau phan ao(khac 0): ";
        i >> x.ao.mau;
    } while (!x.ao.mau);
    
    return i;
}

ostream& operator<<(ostream& o, struct ComplexNumbersFraction x)
{
    if(x.thuc.tu > 0)
    {
        if(x.thuc.mau > 0)
        {
            if(!x.ao.tu) o << x.thuc.tu << "/" << x.thuc.mau << endl;
            else if(x.ao.tu > 0)
            {
                if(x.ao.mau > 0) o << x.thuc.tu << "/" << x.thuc.mau << "+" << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                else
                {
                    x.ao.tu = -x.ao.tu;
                    x.ao.mau = -x.ao.mau;
                    o << x.thuc.tu << "/" << x.thuc.mau << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                } 
                    
            }
            else
            {
                if(x.ao.mau > 0) o << x.thuc.tu << "/" << x.thuc.mau << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                else
                {
                    x.ao.tu = -x.ao.tu;
                    x.ao.mau = -x.ao.mau;
                    o << x.thuc.tu << "/" << x.thuc.mau << "+" << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                } 
            }
        }
        else
        {
            x.thuc.tu = -x.thuc.tu;
            x.thuc.mau = -x.thuc.mau;
            if(!x.ao.tu) o << x.thuc.tu << "/" << x.thuc.mau << endl;
            else if(x.ao.tu > 0)
            {
                if(x.ao.mau > 0) o << x.thuc.tu << "/" << x.thuc.mau << "+" << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                else
                {
                    x.ao.tu = -x.ao.tu;
                    x.ao.mau = -x.ao.mau;
                    o << x.thuc.tu << "/" << x.thuc.mau << x.ao.tu << x.ao.mau << "i" << endl;
                } 
            }
            else
            {
                if(x.ao.mau > 0) o << x.thuc.tu << "/" << x.thuc.mau << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                else
                {
                    x.ao.tu = -x.ao.tu;
                    x.ao.mau = -x.ao.mau;
                    o << x.thuc.tu << "/" << x.thuc.mau << "+" << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                } 
            }
        }
    }
    else if(x.thuc.tu < 0)
    {
        if(x.thuc.mau > 0)
        {
            if(!x.ao.tu) o << x.thuc.tu << "/" << x.thuc.mau << endl;
            else if(x.ao.tu > 0)
            {
                if(x.ao.mau > 0) o << x.thuc.tu << "/" << x.thuc.mau << "+" << x.ao.tu << "/" << x.ao.mau << endl;
                else
                {
                    x.ao.tu = -x.ao.tu;
                    x.ao.mau = -x.ao.mau;
                    o << x.thuc.tu << "/" << x.thuc.mau << x.ao.tu << x.ao.mau << "i" << endl;
                } 
            }
            else
            {
                if(x.ao.mau > 0) o << x.thuc.tu << "/" << x.thuc.mau << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                else
                {
                    x.ao.tu = -x.ao.tu;
                    x.ao.mau = -x.ao.mau;
                    o << x.thuc.tu << "/" << x.thuc.mau << "+" << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                } 
            }
        }
        else
        {
            x.thuc.tu = -x.thuc.tu;
            x.thuc.mau = -x.thuc.mau;
            if(!x.ao.tu) o << x.thuc.tu << "/" << x.thuc.mau << endl;
            else if(x.ao.tu > 0)
            {
                if(x.ao.mau > 0) o << x.thuc.tu << "/" << x.thuc.mau << "+" << x.ao.tu << "/" << x.ao.mau << endl;
                else
                {
                    x.ao.tu = -x.ao.tu;
                    x.ao.mau = -x.ao.mau;
                    o << x.thuc.tu << "/" << x.thuc.mau << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                } 
            }
            else
            {
                if(x.ao.mau > 0) o << x.thuc.tu << "/" << x.thuc.mau << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                else
                {
                    x.ao.tu = -x.ao.tu;
                    x.ao.mau = -x.ao.mau;
                    o << x.thuc.tu << "/" << x.thuc.mau << "+" << x.ao.tu << "/" << x.ao.mau << "i" << endl;
                } 
            }
        }
    }
    else
    {
        if(!x.ao.tu) o << x.thuc.tu << endl;
        else if(x.ao.tu > 0)
        {
            if(x.ao.mau > 0) o << x.ao.tu << "/" << x.ao.mau << "i" << endl;
            else
            {
                x.ao.tu = -x.ao.tu;
                x.ao.mau = -x.ao.mau;
                o << x.ao.tu << x.ao.mau << "i" << endl;
            } 
        }
        else
        {
            if(x.ao.mau > 0) o << x.ao.tu << "/" << x.ao.mau << "i" << endl;
            else
            {
                x.ao.tu = -x.ao.tu;
                x.ao.mau = -x.ao.mau;
                o << x.ao.tu << "/" << x.ao.mau << "i" << endl;
            } 
        }
    }
    return o;
}

struct ComplexNumbersFraction operator/(struct ComplexNumbers x, struct ComplexNumbers y)
{
    ComplexNumbersFraction tmp;
    tmp.thuc.tu = x.thuc*y.thuc + x.ao*y.ao;
    tmp.thuc.mau = y.thuc*y.thuc + y.ao*y.ao;
    tmp.ao.tu = x.thuc*y.ao - x.ao*y.thuc;
    tmp.ao.mau = y.thuc*y.thuc + y.ao*y.ao;
    return tmp;
}

struct ComplexNumbersFraction operator+(struct ComplexNumbersFraction x, struct ComplexNumbersFraction y)
{
    ComplexNumbersFraction tmp;
    tmp.thuc.tu = x.thuc.tu*y.thuc.mau + x.thuc.mau*y.thuc.tu;
    tmp.thuc.mau = x.thuc.mau * y.thuc.mau;
    tmp.ao.tu = x.ao.tu*y.ao.mau + x.ao.mau*y.ao.tu;
    tmp.ao.mau = x.ao.mau * y.ao.mau;
    return tmp;
}

struct ComplexNumbersFraction operator+(struct ComplexNumbersFraction x, double y)
{
    x.thuc.tu = x.thuc.tu + y*x.thuc.mau;
    return x;
}

struct ComplexNumbersFraction operator+(struct ComplexNumbersFraction x, struct Fraction y)
{
    x.thuc.tu = x.thuc.tu*y.mau - x.thuc.mau*y.tu;
    x.thuc.mau = x.thuc.mau * y.mau;
    return x;
}

struct ComplexNumbersFraction operator-(struct ComplexNumbersFraction x, struct ComplexNumbersFraction y)
{
    ComplexNumbersFraction tmp;
    tmp.thuc.tu = x.thuc.tu*y.thuc.mau - x.thuc.mau*y.thuc.tu;
    tmp.thuc.mau = x.thuc.mau * y.thuc.mau;
    tmp.ao.tu = x.ao.tu*y.ao.mau - x.ao.mau*y.ao.tu;
    tmp.ao.mau = x.ao.mau * y.ao.mau;
    return tmp;
}