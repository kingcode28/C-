#include <iostream>
#include <queue>

using namespace std;

int isPrime(int n);
void phanTichThuaSoNguyenTo(queue<int> &dsSNT, int n);

int main() {
    int n;
    queue<int> dsSNT;
    cin >> n;
    phanTichThuaSoNguyenTo(dsSNT, n);
    while(!dsSNT.empty()) {
        cout << dsSNT.front() << endl;
        dsSNT.pop();
    }
    return 0;
}

int isPrime(int n) {
    if(n < 2) return 0;
    else {
        if(n == 2) return 1;
        if(n%2 == 0) return 0;
        for(int i = 3; i*i <= n; i+=2)
            if(n%i == 0) return 0;
        return 1;
    }
}

void phanTichThuaSoNguyenTo(queue<int> &dsSNT, int n) {
    int nCopy = n;
    int snt = 2;
    while(nCopy != 1) {
        while((nCopy % snt) != 0) {
            for(int i = snt+1; i <= nCopy; i++) {
                if(isPrime(i)) {
                    snt = i;
                    break;
                }
            }
        }
        dsSNT.push(snt);
        nCopy /= snt;
    }
}
