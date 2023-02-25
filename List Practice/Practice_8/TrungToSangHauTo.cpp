#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int doUuTien(char c);
string hauTo(string pfx);
int tinhBieuThucHauTo(string pfx);

int main() {
    string pfx = "5 *(3 -1)";
    /* getline(cin, pfx); */
    cout << hauTo(pfx) << endl;
    cout << tinhBieuThucHauTo(hauTo(pfx)) << endl;
    return 0;
}

int doUuTien(char c) {
    if(c == '(') 
        return 0;
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/' || c == '%')
        return 2;
    return 3;
}

string hauTo(string infx) {
    string pfx = "", so = "";
    stack<char> kiTu;
    int i = 0;
    while (i < infx.length()) {
        if(infx[i] != ' ') {
            if((infx[i] >= '0') && (infx[i] <= '9') || isalpha(infx[i])) {
                so = so + infx[i];
            }
            else {
                pfx = pfx + so + " ";
                so = "";
                if(infx[i] == '(') {
                    kiTu.push(infx[i]);
                }
                else {
                    if(infx[i] == ')') {
                        while(kiTu.top() != '(') {
                            pfx = pfx + kiTu.top();
                            kiTu.pop();
                        }
                        kiTu.pop();
                    }
                    else {
                        while(!kiTu.empty() && (doUuTien(kiTu.top()) >= doUuTien(infx[i]))) {
                            pfx = pfx + kiTu.top();
                            kiTu.pop();
                        }
                        kiTu.push(infx[i]);
                    }
                }
            }
        }
        i++;
    } 
    if(so != "") 
        pfx = pfx + so + " ";
    while(!kiTu.empty()) {
        pfx = pfx + kiTu.top();
        kiTu.pop();
    }
    return pfx;
}

int tinhBieuThucHauTo(string pfx) {
    stack<int> kiTu;
    string so = "";
    int i = 0;
    while(i < pfx.length()) {
        if(pfx[i] != ' ') {
            if(pfx[i] >= '0' && pfx[i] <= '9') {
                so = so + pfx[i];
            }
            else {
                int a, b;
                a = kiTu.top(); kiTu.pop();
                b = kiTu.top(); kiTu.pop();
                switch (pfx[i]) {
                    case '+': 
                        kiTu.push(b + a);
                        break;
                    case '-':
                        kiTu.push(b - a);
                        break;
                    case '*':
                        kiTu.push(b * a);
                        break;
                    case '/':
                        kiTu.push(b / a);
                        break;
                    case '%':
                        kiTu.push(b % a);
                        break;
                    case '^':
                        kiTu.push(pow(b, a));
                        break;
                }
            }
        }
        else {
            if(so != "") {
                kiTu.push(stoi(so));
                so = "";
            }
        }
        i++;
    }
    return kiTu.top();
}
