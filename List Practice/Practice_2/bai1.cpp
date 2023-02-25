#include <iostream>

using namespace std;

int main()
{
    int soTaiKhoan;
    char loaiDichVu; 
    float phut;
    float soTienPhaiTra;
    float soTienPhaiTraBanNgay;
    float soTienPhaiTraBanDem;
    float phutBanNgay;
    float phutBanDem;
    
    cout << "Nhap so tai khoan: ";
    cin >> soTaiKhoan;
    cout << "Chon dich vu thong thuong(r or R) hay cao cap(p or P): ";
    cin >> loaiDichVu;
    /*
    Có 2 loại dịch vụ thông thường(r or R) và cao cấp(p or P)
    - Thông thường 50p đầu miễn phí sau 50p thì tính phí 0.2$ mỗi phút
    - Cao cấp có dịch vụ ban ngày và ban đêm
        + Ban ngày: 75p đầu free sau 75p thì tính 0.1$ mỗi phút
        + Ban đêm: 100p đầu free sau 100p thì tính 0.05$ mỗi phút
    */
    switch (loaiDichVu)
    {
        case 'r':
        case 'R':
            cout << "So phut su dung dich vu thong thuong: ";
            cin >> phut;
            if(phut <= 50) {
                soTienPhaiTra = 0;
            }
            else {
                soTienPhaiTra = (phut - 50) * 0.2;
            }
            break;
        case 'p':
        case 'P':
            cout << "So phut su dung dich vu ban ngay(6h-18h): ";
            cin >> phutBanNgay;
            if(phutBanNgay <= 75) {
                soTienPhaiTraBanNgay = 0;
            }
            else {
                soTienPhaiTraBanNgay = (phutBanNgay - 75) * 0.1;
            }
            cout << "So phut su dung dich vu ban dem(18h-6h): ";
            cin >> phutBanDem;
            if(phutBanDem <= 100) {
                soTienPhaiTraBanDem = 0;
            }
            else {
                soTienPhaiTraBanDem = (phutBanDem - 100) * 0.05;
            }
            soTienPhaiTra = soTienPhaiTraBanNgay + soTienPhaiTraBanDem;
            break;
        default:
            cout << "Loi";
            break;
            return 0;
    }
    
    cout << "So tai khoan: " << soTaiKhoan << endl;
    if(loaiDichVu == 'r' || loaiDichVu == 'R') {
        cout << "Loai dich vu: Pho thong" << endl;
        cout << "So phut su dung: " << phut << endl;
    }
    else {
        cout << "Loai dich vu: Cao cap" << endl;
        cout << "So phut su dung ban ngay: " << phutBanNgay << endl;
        cout << "So phut su dung ban dem: " << phutBanDem << endl;
    }
    cout << "So tien phai tra: " << soTienPhaiTra;
    
    return 0;
}