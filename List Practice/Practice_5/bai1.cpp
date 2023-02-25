#include <iostream>

using namespace std;

int tongBinhPhuong(int);

int main()
{
    cout << tongBinhPhuong(5);
    return 0;
}

int tongBinhPhuong(int n)
{
    if(n == 1) return 1;
    else
        return n*n + tongBinhPhuong(n - 1);
}