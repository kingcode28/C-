#include <iostream>

#define fu(i, n) for(int i = 0; i < n; i++) 
using namespace std;

int countEven(int*, int);

int main()
{
    int n = 8;
    int a[] = {1, 2, 3, 4, 5, 6, 6, 8};
    cout << countEven(a, n);
    return 0;
}

int countEven(int* arr, int size) {
    int count = 0;
    int *ptr;
    ptr = arr;

    for(int i = 0; i < size; i++) {
        if(*(ptr + i) % 2 == 0) {
            count++;
        }
    }
    return count;
}