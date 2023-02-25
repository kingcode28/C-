#include <iostream>

using namespace std;

double* maximum(double* a, int n) {
    double *max;
    max = a;

    if(a == NULL) return NULL;
    else {
        for(int i = 1; i < n; i++) {
            if(*max < *(a + i))
                max = a + i;
        }
    }

    return max;
}

int main()
{
    int n = 5;
    double a[] = {3, 4, 1, 9, 2};
    cout << maximum(a, n) << endl;
    return 0;
}