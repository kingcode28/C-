#include <iostream>

using namespace std;

int main()
{
    const float THUE_THU_NHAP = 0.14; // Thuế thu nhập cá nhân 14%

    int soTuanLamViec = 5;
    int tongGioLam = 0;
    int soGioLamMotTuan;
    float luongGio, luongTruocThue, luongSauThue;
    float tienMuaDoCaNhan, tienDungCuHocTap, tienMuaTraiPhieu;
    float tienMuaThemTraiPhieu;

    cout << "Muc luong mot gio: ";
    cin >> luongGio;
    for(int i = 1; i <= soTuanLamViec; i++) // Nhập và cộng tổng số giờ làm của mỗi tuần
    {
        cout << "So gio lam tuan " << i << ": ";
        cin >> soGioLamMotTuan;
        tongGioLam += soGioLamMotTuan;
    }
    // Câu a: Thu nhập trước và sau thuế
    luongTruocThue = luongGio * tongGioLam;
    luongSauThue = luongTruocThue - (luongTruocThue * 0.14);

    // Câu b: Số tiền chi để mua quần áo và các phụ kiện 10% lương sau thuế
    tienMuaDoCaNhan = luongSauThue * 0.1;
    
    // Câu c: Số tiền mua dụng cụ học tập 1% lương sau thuế
    tienDungCuHocTap = luongSauThue * 0.01;

    // Câu d: Tiền mua trái phiếu tiết kiệm 25% tiền còn lại sau khi mua quần áo và dụng cụ học tập
    tienMuaTraiPhieu = (luongSauThue - tienMuaDoCaNhan - tienDungCuHocTap) * 0.25;

    // Câu e: Tiền bố mẹ mua thêm trái phiếu tiết kiệm cho bạn 50% tiền mua trái phiếu của bạn
    tienMuaThemTraiPhieu = tienMuaTraiPhieu * 0.5;

    cout << "Luong truoc thue = " << luongTruocThue << endl;
    cout << "Luong sau thue = " << luongSauThue << endl;
    cout << "Tien mua quan ao va cac phu kien = " << tienMuaDoCaNhan << endl;
    cout << "Tien mua dung cu hoc tap = " << tienDungCuHocTap << endl;
    cout << "Tien trai phieu tiet kiem cua ban = " << tienMuaTraiPhieu << endl;
    cout << "Tien bo me mua them trai phieu tiet kiem cho ban = " << tienMuaThemTraiPhieu << endl;
}