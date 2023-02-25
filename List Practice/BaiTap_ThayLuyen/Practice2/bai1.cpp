#include <iostream>
#include <cmath>

#define swap(a, b) {int t = a; a = b; b = t;}
using namespace std;

int isPrime(int n) {
    if(n < 2) return 0;
    else {
        if(n == 2) return 1;
        if(n % 2 == 0) return 0;
        for(int i = 3; i*i <= n; i += 2) {
            if(n % i == 0) return 0;
        }
        return 1;
    }
}

bool isPerfectNumber(int n) {
    if(n < 6) return false;
    else {
        int tong = 0;
        for(int i = 1; i <= n/2; i++) {
            if(n % i == 0) tong += i;
        }
        return tong == n;
    }
}

void sapTang(int a[], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if( a[i] > a[j] ) {
                swap( a[i], a[j]);
            }
        }
    }
}

void hienThi(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int soDaoNguoc(int n) {
    int soNguoc = 0;
    while (n > 0) {
        soNguoc = soNguoc*10 + n%10;
        n /= 10;
    }
    return soNguoc;
}

bool isSymmetricalNumber(int n) { // Là số đối xứng
    if( n == soDaoNguoc(n) ) return true;
    return false;
}

float average(int a[], int n) {
    int tong = 0;
    for(int i = 0; i < n; i++) {
        tong = tong + a[i];
    }
    return (float) tong / n;
}

int main()
{
    int n = 5;
    int a[] = {1, 2, 5, 5, 4};


    // 1. Cho biết trung bình cộng các số trong dãy vừa nhập
    // cout << "TBC = " << average(a, n); 
    
    // 2. Cho biết trong dãy vừa nhập có bao nhiêu số nguyên tố, và đó là những số nào.
    // for(int i = 0; i < n; i++) {
    //     if( isPrime(a[i]) ) {
    //         cout << a[i] << " ";
    //     }
    // }

    //3. Cho biết trong dãy vừa nhập có bao nhiêu số hoàn hảo và đó là những số nào.
    // for(int i = 0; i < n; i++) {
    //     if( isPerfectNumber(a[i]) ) {
    //         cout << a[i] << " ";
    //     }
    // }
    
    //4. In ra dãy số sau khi sắp xếp tăng dần.
    // sapTang(a, n);
    // hienThi(a, n);
    
    //5. Cho biết số lớn nhất trong dãy là số nào và ở vị trí nào tính từ trái sang (tính từ vị trí 1) theo thứ tự nhập ban đầu.
    // int max = a[0];
    // int iMax = 0;
    // for(int i = 1; i < n; i++) {
    //     if( a[i] > max) {
    //         max = a[i];
    //         iMax = i;
    //     }
    // }
    // cout << "Max = " << max << endl;
    // cout << "Vi Tri = " << iMax + 1 << endl;

    //6. In ra dãy số ban đầu với các số được in đảo ngược
    // for(int i = 0; i < n; i++) {
    //     cout << soDaoNguoc(a[i]) << " ";
    // }

    //7. Cho biết trong dãy vừa nhập có bao nhiêu số đối xứng và đó là những số nào.
    // for(int i = 0; i < n; i++) {
    //     if( isSymmetricalNumber(a[i]) ) {
    //         cout << a[i] << " ";
    //     }
    // }

    //8. Cho biết số gần với số trung bình cộng nhất là số nào.
    // float tbc = average(a, n);
    // float hieu = fabs(a[0] - tbc);
    // int iNear = 0;
    // for(int i = 1; i < n; i++) {
    //     if(hieu > fabs(a[i] - tbc)) {
    //         hieu = fabs(a[i] - tbc);
    //         iNear = i;
    //     }
    // }
    // cout << a[iNear] << endl;
    // cout << tbc;

    return 0;
}