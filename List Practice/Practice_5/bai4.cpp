#include <iostream>
#include <cmath>

#define EPSILON 0.0001

using namespace std;

double canBacHai(double, double);

int main()
{
    cout << canBacHai(2 , 2);
    return 0;
}

double canBacHai(double x, double a)
{
    if(fabs(a*a - x) <= EPSILON) return a;
    else
        return canBacHai(x, (a*a + x) / (2*a));
}