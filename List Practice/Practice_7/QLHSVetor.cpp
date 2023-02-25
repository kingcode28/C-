#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <conio.h>

#define ESC 27

using namespace std;

struct HocSinh {
    string maHS;
    string hoTen;
    unsigned int namSinh;
    string queQuan;
};

void nhapHS(struct HocSinh& a);
void nhapCacHS(vector<HocSinh>& hs, int n);
void inHS(struct HocSinh a);
void inCacHS(vector<HocSinh> hs);
void ghiTep(vector<HocSinh> hs, string tenTep);
void docTep(vector<HocSinh>& hs, string tenTep);
int timHS(vector<HocSinh> hs, string maSV);
int chenHS(vector<HocSinh> hs, struct HocSinh a, int index);
int xoaHS(vector<HocSinh> &hs, int vt);
void sapXepGiamDanTheoMaHS(vector<HocSinh> &hs);
int menu();

int main()
{
    vector<HocSinh> hs;
    int chon;
    do
    {
        chon = menu();
        if(chon == ESC) break;
        switch (chon)
        {
            case '1': {
                int soHS;
                cout << "Nhap so hoc sinh can nhap: ";
                cin >> soHS;
                nhapCacHS(hs, soHS);
                break;
            }
            case '2': {
                ghiTep(hs,"D:\\C++\\Practice_7\\DATA.OUT");
                break;
            }
            case '3': {
                inCacHS(hs);
                break;
            }
            case '4': {
                docTep(hs,"D:\\C++\\Practice_7\\DATA.INP");
                break;
            }
            case '5': {
                string ma;
                cout << "Nhap ma hoc sinh can tim: ";
                cin >> ma;
                inHS(hs[timHS(hs, ma)]);
                break;
            }
            case '6': {
                int viTri;
                HocSinh hsCanChen;
                nhapHS(hsCanChen);
                cout << "Nhap vi tri can chen vao: ";
                cin >> viTri;
                chenHS(hs, hsCanChen, viTri);
                break;
            }
            case '7': {
                string maHS;
                cout << "Nhap ma hoc sinh can xoa";
                cin >> maHS;
                xoaHS(hs,timHS(hs, maHS));
                break;
            }
            case '8': {
                sapXepGiamDanTheoMaHS(hs);
                break;
            }
            default:
                cout << "Nhap sai! Vui long nhap tu 1-8" << endl;
        }
        system("pause");
    } while (chon != ESC);
    
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

void nhapCacHS(vector<HocSinh>& hs, int n) {
    HocSinh a;
    for(int i = 0; i < n; i++) {
        nhapHS(a);
        hs.push_back(a);
    }
}

void inHS(struct HocSinh a) {
    cout << setw(13) << left << a.maHS
         << setw(20) << left << a.hoTen
         << setw(12) << left << a.namSinh
         << setw(15) << left << a.queQuan
         << endl;
}

void inCacHS(vector<HocSinh> hs) {
    cout << "-----THONG TIN CAC HOC SINH-----" << endl;
    cout << setw(13) << left << "Ma HS"
         << setw(20) << left << "Ho Ten"
         << setw(12) << left << "Nam sinh"
         << setw(15) << left << "Que quan"
         << endl;
    vector<HocSinh>::iterator i;
    for(i = hs.begin(); i != hs.end(); i++) {
        inHS(*i);
    }
}

int timHS(vector<HocSinh> hs, string maSV) {
    vector<HocSinh>::iterator i;
    for(i = hs.begin(); i != hs.end(); i++) {
        if(i->maHS.compare(maSV)) {
            return (i-hs.begin()) - 1;
        }
    }
    return -1;
}

int chenHS(vector<HocSinh> hs, struct HocSinh a, int index) {
    if(index < 0 || index > hs.size())
        return -1;
    vector<HocSinh>::iterator i;
    hs.insert(hs.begin() + index, a);
    return index;
}

int xoaHS(vector<HocSinh> &hs, int vt) {
    if(vt >= 0 && vt <= hs.size()) {
        vector<HocSinh>::iterator i;
        hs.erase(hs.begin() + vt);
        return vt;
    }
    return -1;
}

void sapXepGiamDanTheoMaHS(vector<HocSinh> &hs) {
    int i, j;
    for(i = 0; i < hs.size()-1; i++) {
        for(j = i+1; j < hs.size(); j++) {
            if(hs[i].maHS.compare(hs[j].maHS) < 0) {
                HocSinh tmp = hs[i];
                hs[i] = hs[j];
                hs[j] = tmp;
            }
        }
    }
}

void ghiTep(vector<HocSinh> hs, string tenTep) {
    ofstream outfile;
    outfile.open(tenTep);
    if(!outfile.is_open()) {
        cout << "Loi ghi file";
        outfile.close();
        exit(0);
    }
    vector<HocSinh>::iterator i;
    for(i = hs.begin(); i != hs.end(); i++) {
        outfile << i->maHS << ";" << i->hoTen<< ";" << i->namSinh << ";" << i->queQuan << endl;
    }
    outfile.close();
}

void docTep(vector<HocSinh>& hs, string tenTep) {
    ifstream infile;
    infile.open(tenTep);
    if(!infile.is_open()) {
        cout << "Loi doc file";
        infile.close();
        exit(0);
    }
    HocSinh a;
    string nam;
    while (!infile.eof())
    {
        getline(infile, a.maHS, ';');
        getline(infile, a.hoTen, ';');
        getline(infile, nam, ';');
        a.namSinh = stoi(nam);  // stoi convent string to int
        getline(infile, a.queQuan);
        hs.push_back(a);
    }
    infile.close();
}

int menu() {
    system("cls");
    cout << "1. Nhap danh sach hoc sinh vao mang" << endl;
    cout << "2. Luu danh sach hoc sinh vao tep" << endl;
    cout << "3. Hien thi tat ca cac hoc sinh" << endl;
    cout << "4. Doc danh sach hoc sinh tu tep" << endl;
    cout << "5. Tim mot hoc sinh theo ma hoc sinh" << endl;
    cout << "6. Chen mot hoc sinh vao danh sach" << endl;
    cout << "7. Xoa mot hoc sinh theo ma hoc sinh" << endl;
    cout << "8. Sap xep danh sach hoc sinh giam dan theo ma hoc sinh" << endl;
    cout << "Nhan ESC de thoat chuong trinh" << endl;
    return _getch();
}
