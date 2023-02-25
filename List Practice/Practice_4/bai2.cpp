#include <iostream>
#include <conio.h>
#include <cmath>

#define ESC 27

using namespace std;

int khoangThanhToanDinhKy() {
    double L, r;
    int m, t, k;
    
    cout << "Nhap so tien vay: "; cin >> L;
    cout << "Nhap lai suat moi nam: "; cin >> r;
    cout << "Nhap so lan thanh toan trong mot nam; "; cin >> m;
    cout << "Nhap khoan vay trong bao nhieu nam: "; cin >> t;

    double i = (r / m);
    double R = (L * i) / (1 - pow(1+i, -m*t));
    
    return R;
}

int soTienSauKLanThanhToan(double L, double r, int m, int t, int k) {
    double i = (r / m);
    double R = khoangThanhToanDinhKy();
    double LPhay = ( R * ( 1 - pow(1+i, -(m*t - k)) ) ) / i;
    return LPhay;
}

int soThangTraHetNo() {
    float soTienVay;
    float laiSuatHangNam;
    float laiSuatHangThang;
    float tienLaiHangThang;
    float khoanThanhToanHangThang;
    int soThangTraNo;

    cout << "Nhap so tien vay: ";
    cin >> soTienVay;
    cout << "Lai suat moi nam (%): ";
    cin >> laiSuatHangNam;
    cout << "Khoan thanh toan hang thang cua ban: ";
    cin >> khoanThanhToanHangThang;

    laiSuatHangThang = laiSuatHangNam / 12;
    laiSuatHangThang = laiSuatHangThang / 100;
    tienLaiHangThang = soTienVay * laiSuatHangThang;
    /*
    Hàng tháng nộp khoản thanh toán hàng tháng
    Lấy số tiền đó trừ cho lãi xuất mỗi tháng
    Còn lại trừ vào tiền vay tiếp tục cho tới khi trả hết tiền vay
    */
    if(khoanThanhToanHangThang <= tienLaiHangThang) {
        cout << "Canh bao! Khoan thanh toan hang thang qua thap.";
    }
    else {
        soThangTraNo = 0;
        while (soTienVay > 0)
        {
            soTienVay = soTienVay - (khoanThanhToanHangThang - tienLaiHangThang);
            tienLaiHangThang = soTienVay * laiSuatHangThang;
            soThangTraNo++;
        }
        cout << "So thang de tra het no: " << soThangTraNo << endl;
    }
}

void menuChon() {
    int chon;
    do
    {
        system("cls");
        cout << "1. So thang tra het no." << endl;
        cout << "2. So tien phai tra hang thang." << endl;
        cout << "Press key ESC to exit" << endl;
        chon = _getch();
        switch (chon)
        {
            system("cls");
            case '1':
                soThangTraHetNo();
                system("pause");
                break;
            case '2':
                cout << "So tien thanh toan hang thang: " << khoangThanhToanDinhKy() << endl;
                system("pause");
                break;
        }
    } while (chon != ESC);
}


int main() {
    menuChon();
    return 0;
}