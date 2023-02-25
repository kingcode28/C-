#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int age;
    
    void getInfo() {
        cout << "Name: "; cin >> this->name;
        cout << "Age: "; cin >> this->age;
    };

    void displayInfo() {
            cout << " " << this->name << " " << this->age << endl;
    };

};



int main() {
    Student student[5];
    int numOfStudent;
    cout << "Enter number of student: ";
    cin >> numOfStudent;

    for(int i = 0; i < numOfStudent; i++) {
        student[i].getInfo();
    }

    cout << "---LIST OF STUDENT---" << endl;
    for(int i = 0; i < numOfStudent; i++) {
        cout << i;
        student[i].displayInfo();
    }

    // Nhập một tên sinh viên và cho biết trong danh sách sinh viên có bao nhiêu bạn có tên vừa nhập.
    int count = 0;
    string ten;
    cout << "Enter a name: "; cin >> ten;
    for(int i = 0; i < numOfStudent; i++) {
        if(student[i].name == ten) count++;
    }    
    cout << "There're " << count << " student which's name: " << ten << endl; 

    // Cho biết độ tuổi trung bình của các bạn sinh viên.
    int tong = 0;
    for(int i = 0; i < numOfStudent; i++) {
        tong += student[i].age;
    }
    cout << "Average of age is " << (float) tong / numOfStudent;
}