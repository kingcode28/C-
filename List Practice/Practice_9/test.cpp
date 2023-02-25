#include <iostream>

using namespace std;

void showPath(int truoc[], int x, int y) {
    if(truoc[y] != 0) {
        if(truoc[y] == x) {
            cout << x << "->" << y;
        }
        else {
            showPath(truoc,x, truoc[y]);
            cout << "->" << y;
        }
    }
    else
        cout << "Khong co duong di tu " << x << "->" << y << endl;
}

int main() {
    int truoc[] = {0, 0, 1, 8, 5, 6, 7, 3, 2, 10, 6, 8};
    showPath(truoc, 1, 5);
    return 0;
}
