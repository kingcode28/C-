#include <iostream>

using namespace std;

void inMang(int a[], int n);
void reversearray(int a[], int n);
// void ptr_reversearray(int* a, int n);

int main()
{
    int n = 4;
    int a[] = {9, -1, 4, 5};
    inMang(a, n);
    reversearray(a, n);
    inMang(a, n);
    return 0;
}

void inMang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void reversearray(int a[], int n) {
    int l = 0, r = n-1, tmp;

    for(int i = 0; i < n/2; i++) {
        tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
        l++; r--;
    }
}

// void ptr_reversearray(int* a, int n) {
//     int l = 0, r = n-1, tmp;

// }