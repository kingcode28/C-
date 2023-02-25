#include <iostream>

using namespace std;

int main()
{
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
    return 0;
}