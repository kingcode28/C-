#include <iostream>

using namespace std;

double power(double, int);

int main()
{
    cout << power(2, -3);
    return 0;
}

double power(double a, int n)
{
    if(n >= 0)
    {
        if(n <= 1) return n == 0 ? 1 : a;
        else
            return a * power(a, n-1);
    }
    else
    {
        if(n == -1) return 1/a;
        else
            return 1/a * power(a, n+1);

    }
}