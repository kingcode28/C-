#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int SECOND_PER_HOUR = 3600;   // 1giờ = 3600giây
    const int SECOND_PER_MINUTE = 60;   // 1phút = 60giây

    int value;  // giá trị đơn vị tính bằng giây
    int hour;   
    int minute;
    int second;

    cout << "Nhap so giay: ";
    cin >> value;

    // đổi value sang giờ:phút: giây
    hour = value / SECOND_PER_HOUR;
    minute = (value % SECOND_PER_HOUR) / SECOND_PER_MINUTE;
    second = value % SECOND_PER_MINUTE;

    cout << setfill('0');
        
    cout << setw(2) << hour << ":" << setw(2) << minute << ":"<< setw(2) << second << endl;
}