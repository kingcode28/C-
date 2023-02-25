#include <iostream>

using namespace std;

void nhapMang(int* a, int n);
void inMang(int* a, int n);
void sapTang(int* a, int n);

int main()
{
    int n;
    int a[] = {2, 45, 2, 5, 2};
    cout << "Nhap so phan tu: ";
    cin >> n;

    // nhapMang(a, n);
    inMang(a, n);
    sapTang(a, n);
    inMang(a, n);
    
    return 0;
}

void nhapMang(int* a, int n) {
    for(int i = 0; i < n; i++) {
        cin >> *(a + i);
    }
}

void inMang(int* a, int n) {
    for(int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl;
}

void sapTang(int* a, int n) {
    int i, j, tmp;

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(*(a + i) > *(a + j)) {
                tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }
}