#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct HocSinh {
    string maHS;
    string hoTen;
    unsigned int namSinh;
    string queQuan;
};
void nhapHS(struct HocSinh& a);
void nhapCacHS(struct HocSinh hs[], int n);
void inHS(struct HocSinh a);
void inCacHS(struct HocSinh hs[], int n);
void ghiTep(struct HocSinh hs[], int n, string tenTep);
void docTep(struct HocSinh hs[], int& n, string tenTep);
int timHS(string maSV);
void chenHS(struct HocSinh hs[], int& n, struct HocSinh a, int index, int length);
int xoaHS(struct HocSinh hs[], int& n, string maHS, int start);
void sapXepGiamDanTheoMaHS(struct HocSinh hs[], int n);

int main()
{
    int n = 0;
    struct HocSinh ds[100];
    // int length = sizeof(ds) / sizeof(ds[0]);
    // nhapCacHS(ds, n);
    // ghiTep(ds, n, "D:\\C++\\Practice_7\\QLHS.txt");
    // inCacHS(ds, n);
    // sapXepGiamDanTheoMaHS(ds, n);
    // inCacHS(ds, n);
    docTep(ds, n, "D:\\C++\\Practice_7\\QLHS.txt");
    inCacHS(ds, n);
    cout << n;
    return 0;
}

void nhapHS(struct HocSinh& a) {
    cout << "Nhap ma hs: ";
    cin >> a.maHS;
    fflush(stdin);
    cout << "Nhap ho ten hs: ";
    getline(cin, a.hoTen);
    cout << "Nhap nam sinh: ";
    cin >> a.namSinh;
    fflush(stdin);
    cout << "Nhap que quan: ";
    getline(cin, a.queQuan);
}

void nhapCacHS(struct HocSinh hs[], int n) {
    for(int i = 0; i < n; i++) {
        nhapHS(hs[i]);
    }
}

void inHS(struct HocSinh a) {
    cout << setw(13) << left << a.maHS
         << setw(20) << left << a.hoTen
         << setw(12) << left << a.namSinh
         << setw(15) << left << a.queQuan
         << endl;
}

void inCacHS(struct HocSinh hs[], int n) {
    cout << setw(4)  << left << "STT"
         << setw(13) << left << "Ma HS"
         << setw(20) << left << "Ho Ten"
         << setw(12) << left << "Nam sinh"
         << setw(15) << left << "Que quan"
         << endl;

    for(int i = 0; i < n; i++) {
        cout << setw(4) << left << (i+1);
        inHS(hs[i]);
    }
}

bool timHS(struct HocSinh hs[], int n, string maHS) {
    for(int i = 0; i < n; i++) {
        if(hs[i].maHS.compare(maHS)) {
            return true;
        }
    }
    return false;


void chenHS(struct HocSinh hs[], int& n, struct HocSinh a, int index, int length) {
    int i, j;
    if(index >= 0 && index <= n) {
        if(n < length) {
            for(i = n; i > index; i--) {
                hs[i] = hs[i-1];
            }
            hs[index] = a;
            n += 1;
        }
    }
}

int xoaHS(struct HocSinh hs[], int& n, string maHS, int start = 0) {
    int i, j;
    for(i = start; i < n; i++) {
        if(hs[i].maHS.compare(maHS)) {
            for(j = i; j < n-1; j++) {
                hs[j] = hs[j+1];
            }
            n -= 1;
            return i;
        }
    }
    return -1;
}

void sapXepGiamDanTheoMaHS(struct HocSinh hs[], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n-1; j++) {
            if(hs[i].maHS.compare(hs[j].maHS) < 0) {
                HocSinh tmp = hs[i];
                hs[i] = hs[j];
                hs[j] = hs[i];
            }
        }
    }
}

void ghiTep(struct HocSinh hs[], int n, string tenTep) {
    ofstream outfile;
    outfile.open(tenTep);
    if(!outfile.is_open()) {
        cout << "Loi ghi file";
        outfile.close();
        exit(0);
    }
    for(int i = 0; i < n; i++) {
        outfile << hs[i].maHS << ";" << hs[i].hoTen<< ";" << hs[i].namSinh << ";" << hs[i].queQuan << endl;
    }
    outfile.close();
}

void docTep(struct HocSinh hs[], int& n, string tenTep) {
    ifstream infile;
    infile.open(tenTep);
    if(!infile.is_open()) {
        cout << "Loi doc file";
        infile.close();
        exit(0);
    }
    n = 0;
    string nam;
    while (!infile.eof())
    {
        getline(infile, hs[n].maHS, ';');
        getline(infile, hs[n].hoTen, ';');
        getline(infile, nam, ';');
        hs[n].namSinh = stoi(nam);  // stoi convent string to int
        getline(infile, hs[n].queQuan);
        n += 1;
    }
    infile.close();
}
