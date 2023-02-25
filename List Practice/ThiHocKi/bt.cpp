#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void openFile(ifstream& input, string fathFileIn, ofstream& output, string fathFileOut);
void initialize(int& countFemale, double& sumFemaleGPA, int& countMale, double& sumMaleGPA);
void sumGrades(int& countFemale, double& sumFemaleGPA, int& countMale, double& sumMaleGPA, ifstream& input);
double averageGrade(double sum, int n);
void printResults(double averageFemale, double averageMale, ofstream& output);
void closeFile(ifstream& input, ofstream& output);

int main() {
    ifstream in;
    ofstream out;
    int countMale;
    int countFemale;
    double sumMaleGPA;
    double sumFemaleGPA;

    openFile(in, "D:\\C++\\ThiHocKi\\data.inp", out, "D:\\C++\\ThiHocKi\\data.out");
    sumGrades(countFemale, sumFemaleGPA, countMale, sumMaleGPA, in);
    printResults(averageGrade(sumFemaleGPA, countFemale), averageGrade(sumMaleGPA, countMale), out);
    closeFile(in, out);
    cout << "Ket thuc chuong trinh" << endl;

    return 0;
}

void openFile(ifstream& input, string fathFileIn, ofstream& output, string fathFileOut) {
    input.open(fathFileIn);
    if(!input.is_open()) {
        cout << "Loi doc file" << endl;
        exit(0);
    }
    output.open(fathFileOut);
    if(!output.is_open()) {
        cout << "Loi ghi file" << endl;
        exit(0);
    }

    output << setprecision(2) << fixed;
}

void initialize(int& countFemale, double& sumFemaleGPA, int& countMale, double& sumMaleGPA) {
    countFemale = 0;
    sumFemaleGPA = 0;
    countMale = 0;
    sumMaleGPA = 0;
}

void sumGrades(int& countFemale, double& sumFemaleGPA, int& countMale, double& sumMaleGPA, ifstream& input) {
    char sex;
    double mediumScore;
    initialize(countFemale, sumFemaleGPA, countMale, sumMaleGPA);
    while(!input.eof()) {
        input >> sex;
        input >> mediumScore;
        if(sex == 'f') {
            countFemale++;
            sumFemaleGPA += mediumScore;
        }
        else {
            countMale++;
            sumMaleGPA += mediumScore;
        }
    }
}

double averageGrade(double sum, int n) {
    return sum / n;
}

void printResults(double averageFemale, double averageMale, ofstream& output) {
    output << "Diem trung binh cua sinh vien nu la: " << averageFemale << endl;
    output << "Diem trung binh cua sinh vien nam la: " << averageMale << endl;
}

void closeFile(ifstream& input, ofstream& output) {
    input.close();
    output.close();
}
