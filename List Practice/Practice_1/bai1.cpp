#include <iostream>

using namespace std;
int main()
{
    // Chuyển đổi độ F sang độ C
    float F, C;
    cout << "Nhap do F: ";
    cin >> F;
    C = 5.0/9 * (F - 32);
    cout << F << " do F = " << C << " do C" << endl;
}