#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n = 100;
    cout << setfill('0');
    for(int i = 1; i <= n; i++) {
        cout << setw(3) << i << ", ";
    }
}