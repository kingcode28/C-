#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iomanip>

#define ESC 27

using namespace std;

struct MonHoc {
    string maMH;
    string tenMH;
    int soTinChi;
    double tiLeQT;
    double tiLeDT;
};

int menu();
void nhapMonHoc(struct MonHoc& a);
void nhapCacMonHoc(vector<MonHoc>& mh, int n);
void hienThiMonHoc(struct MonHoc a);
void hienThiCacMonHoc(vector<MonHoc> mh);
int timMonHocCoSoTC(vector<MonHoc> mh, int soTC, int iBegin = 0);
void hienThiCacMonHocCoSoTC(vector<MonHoc> mh, int soTC);
void docFile(vector<MonHoc>& mh, string tenFile);
void ghiFile(vector<MonHoc> mh, string tenFile);

int main() {
    vector<MonHoc> mh;
    int chon;

    do {
        chon = menu();
        if(chon == ESC) break;
        switch (chon) {
            case '1': {
                int n;
                cout << "Nhap so mon hoc can nhap: ";
                cin >> n;
                nhapCacMonHoc(mh, n);
                break;
            }
            case '2': {
                hienThiCacMonHoc(mh);
                system("pause");
                break;
            }
            case '3': {
                ghiFile(mh, "D:\\C++\\ThiHocKi\\THI.INP");
                cout << "Ghi file thanh cong!" << endl;
                system("pause");
                break;
            }
            case '4': {
                docFile(mh, "D:\\C++\\ThiHocKi\\THI.INP");
                cout << "Doc file thanh cong!" << endl;
                system("pause");
                break;
            }
            case '5': {
                int soTC;
                cout << "Nhap so tin chi: ";
                cin >> soTC;
                hienThiCacMonHocCoSoTC(mh, soTC);
                system("pause");
                break;
            }
                
            default:
                break;
        }
        
    } while (chon != ESC);
    return 0;
}

int menu() {
    system("cls");
    cout << "1. Nhap danh sach mon hoc" << endl;
    cout << "2. Hien thi tat ca cac mon hoc" << endl;
    cout << "3. Luu danh sach cac mon hoc" << endl;
    cout << "4. Doc danh sach cac mon hoc" << endl;
    cout << "5. Liet ke cac mon hoc co so tin chi giong nhau" << endl;
    cout << "ESC. Thoat khoi chuong trinh" << endl;
    return _getch();
}

void nhapMonHoc(struct MonHoc& a){
    cout << "Nhap ma mon hoc: ";
    cin >> a.maMH;
    fflush(stdin);
    cout << "Nhap ten mon hoc: ";
    getline(cin, a.tenMH);
    cout << "Nhap so tin chi: ";
    cin >> a.soTinChi;
    cout << "Nhap ti le diem qua trinh: ";
    cin >> a.tiLeQT;
    cout << "Nhap ti le diem thi: ";
    cin >> a.tiLeDT;
    fflush(stdin);
}

void nhapCacMonHoc(vector<MonHoc>& mh, int n) {
    MonHoc a;
    for(int i = 0; i < n; i++) {
        nhapMonHoc(a);
        mh.push_back(a);
    }
}

void hienThiMonHoc(struct MonHoc a) {
    cout << setw(10) << left << a.maMH
         << setw(20) << left << a.tenMH
         << setw(20) << left << a.soTinChi
         << setw(20) << left << a.tiLeQT
         << setw(20) << left << a.tiLeDT << endl;
}

void hienThiCacMonHoc(vector<MonHoc> mh) {
    cout << "-----Danh sach cac mon hoc-----" << endl;
    cout << setw(10) << left << "Ma MH"
         << setw(20) << left << "Ten MH"
         << setw(20) << left << "So TC"
         << setw(20) << left << "Ti le QT"
         << setw(20) << left << "Ti le DT" << endl;
    vector<MonHoc>::iterator i;
    for(i = mh.begin(); i != mh.end(); i++) {
        hienThiMonHoc(*i);
    }
}

int timMonHocCoSoTC(vector<MonHoc> mh, int soTC, int iBegin) {
    vector<MonHoc>::iterator i;
    for(i = mh.begin() + iBegin; i != mh.end(); i++) {
        if(i->soTinChi == soTC) {
            return i - mh.begin();
        }
    }
    return -1;
}

void hienThiCacMonHocCoSoTC(vector<MonHoc> mh, int soTC) {
    int viTri = timMonHocCoSoTC(mh, soTC);

    if(viTri != -1) {
        cout << "-----Danh sach mon hoc co " << soTC << " tin chi-----" << endl;
        cout << setw(10) << left << "Ma MH"
             << setw(20) << left << "Ten MH"
             << setw(20) << left << "So TC"
             << setw(20) << left << "Ti le QT"
             << setw(20) << left << "Ti le DT" << endl;
        do {
            hienThiMonHoc(*(mh.begin() + viTri));
            viTri = timMonHocCoSoTC(mh, soTC, viTri + 1);
        } while (viTri != -1);
    }
    else {
        cout << "Khong co mon hoc nao co " << soTC << " tin chi" << endl;
    }
}

void ghiFile(vector<MonHoc> mh, string tenFile) {
    ofstream out;
    out.open(tenFile);

    if(!out.is_open()) {
        cout << "Loi ghi file" << endl;
        exit(0);
    }
    out << mh.size() << endl;
    vector<MonHoc>::iterator i;
    for(i = mh.begin(); i != mh.end(); i++) {
        out << i->maMH << "\t" << i->tenMH << "\t" << i->soTinChi << "\t" << i->tiLeQT << "\t" << i->tiLeDT << endl;
    }

    out.close();
}

void docFile(vector<MonHoc>& mh, string tenFile) {
    ifstream in;
    in.open(tenFile);

    if(!in.is_open()) {
        cout << "Loi doc file" << endl;
        exit(0);
    }
    int n;
    MonHoc a;
    in >> n;
    for(int i = 0; i < n; i++) {
        in >> a.maMH >> a.tenMH >> a.soTinChi >> a.tiLeQT >> a.tiLeDT;
        mh.push_back(a);
    }

    in.close();
}
