#include <iostream>
#include <cstdio>

using namespace std;

bool isPrime(int n);
bool isSymmetricalNumber(int n);

int main()
{
    freopen("PRIME.INP", "r", stdin);
    freopen("PRIME.OUT", "w", stdout);
    int a, b;
    bool flag = false;
    cin >> a >> b;
    for(int i = a+(a+1)%2; i <= b; i+=2)
    {
        if(isPrime(i))
        {
            if(isSymmetricalNumber(i))
            {
                flag = true;
                cout << i << "\n";
            }
        }
    }
    if(!flag)
        cout << 0;
    return 0;
}

bool isPrime(int n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(int i = 3; i*i <= n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

bool isSymmetricalNumber(int n)
{
    int nCopy, symNum;
    nCopy = n;
    symNum = 0;
    while(nCopy)
    {
        symNum = symNum*10 + nCopy%10;
        nCopy /= 10;
    }
    return n == symNum ? true : false;
}
