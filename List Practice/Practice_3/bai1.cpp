#include <iostream>
#include <conio.h>

#define ESC 27
#define TAB 9
#define VN_US 1
#define US_VN -1
#define BACK 48

using namespace std;

void menuChucNangVN();
void menuChucNangUS();

void menuChucNang1VN();
void menuChucNang2VN();
void menuChucNang3VN();

void menuChucNang1US();
void menuChucNang2US();
void menuChucNang3US();

void xoaManHinh();
void tamDung();

double cmToInch(double cm);
double dmToFoot(double dm);
double mToYard(double m);
double kmToMile(double km);

double inchToCm(double inch);
double footToDm(double foot);
double yardToM(double yard);
double mileToKm(double mile);

double grToOunce(double gr);
double kgToPound(double kg);
double tanToTon(double tan);

double ounceToGr(double ounce);
double poundToKg(double pound);
double tonToTan(double ton);

double fahrenheitToCelsius(double f);
double celsiusToFahrenheit(double c);

double kenvinToCelsius(double k);
double celsiusToKenvin(double c);

int main() {

    int chon;
    int mode = VN_US;

    do
    {
        xoaManHinh();

        /*Menu Chính*/
        if(mode == VN_US) {
            menuChucNangVN();
        }else {
            menuChucNangUS();   
        }

        chon = _getch();

        switch (chon)
        {
            /*Menu chức năng 1*/
            case '1': 
                do
                {
                    xoaManHinh();
                    if(mode == VN_US) {
                        menuChucNang1VN();
                    } else {
                        menuChucNang1US();
                    }
                    
                    chon = _getch();
                    switch (chon)
                    {
                        // 1.1 inch -> cm && cm -> inch
                        case '1':
                            double inch, cm;
                            if(mode == VN_US) {
                                cout << "Nhap don vi cm: ";
                                cin >> cm;
                                cout << "Don vi inch: " << cmToInch(cm) << endl;
                            } else {
                                cout << "Enter inch: ";
                                cin >> inch;
                                cout << "Cm: " << inchToCm(inch) << endl;
                            }
                            tamDung();
                            break;

                        // 1.2 foot -> dm && dm -> foot
                        case '2':
                            double foot, dm;
                            if(mode == VN_US) {
                                cout << "Nhap don vi dm: ";
                                cin >> dm;
                                cout << "Don vi foot: " << dmToFoot(dm) << endl;
                            } else {
                                cout << "Enter foot: ";
                                cin >> foot;
                                cout << "Dm: " << footToDm(foot) << endl;
                            }
                            tamDung();
                            break;

                        // 1.3 yard -> m && m -> yard
                        case '3':
                            double yard, m;
                            if(mode == VN_US) {
                                cout << "Nhap don vi m: ";
                                cin >> m;
                                cout << "Don vi yard: " << mToYard(m) << endl;
                            } else {
                                cout << "Enter yard: ";
                                cin >> yard;
                                cout << "M: " << yardToM(yard) << endl;
                            }
                            tamDung();
                            break;

                        // 1.4 mile -> km && km -> mile
                        case '4':
                            double mile, km;
                            if(mode == VN_US) {
                                cout << "Nhap don vi km: ";
                                cin >> km;
                                cout << "Don vi mile: " << kmToMile(km) << endl;
                            } else {
                                cout << "Enter mile: ";
                                cin >> mile;
                                cout << "Km: " << mileToKm(mile) << endl;
                            }
                            tamDung();
                            break;

                        // VN -> US && US -> VN
                        case TAB:
                            mode = - mode;
                            break;
                    }
                } while (chon != BACK);
                break;

            /*Menu chức năng 2*/
            case '2':
                do
                {
                    xoaManHinh();
                    if(mode == VN_US) {
                        menuChucNang2VN();
                    } else {
                        menuChucNang2US();
                    }

                    chon = _getch();
                    switch (chon)
                    {
                        // 2.1 ounce -> gr && gr -> onuce
                        case '1':
                            double ounce, gr;
                            if(mode == VN_US) {
                                cout << "Nhap don vi gr: ";
                                cin >> gr;
                                cout << "Don vi ounce: " << grToOunce(gr) << endl;
                            } else {
                                cout << "Enter ounce: ";
                                cin >> ounce;
                                cout << "Gr: " << ounceToGr(ounce) << endl;
                            }
                            tamDung();
                            break;

                        // 2.2 pound -> kg && kg -> pound
                        case '2':
                            double pound, kg;
                            if(mode == VN_US) {
                                cout << "Nhap don vi kg: ";
                                cin >> kg;
                                cout << "Don vi pound: " << kgToPound(kg) << endl;
                            } else {
                                cout << "Enter pound: ";
                                cin >> pound;
                                cout << "Kg: " << poundToKg(pound) << endl;
                            }
                            tamDung();
                            break;


                        // 2.3 ton -> tấn && tấn -> ton
                        case '3':
                            double ton, tan;
                            if(mode == VN_US) {
                                cout << "Nhap don vi tan: ";
                                cin >> tan;
                                cout << "Don vi ton: " << tanToTon(tan) << endl;
                            } else {
                                cout << "Enter ton: ";
                                cin >> ton;
                                cout << "Tan: " << tonToTan(ton) << endl;
                            }
                            tamDung();
                            break;
                        
                        // VN -> US && US -> VN
                        case TAB: 
                            mode = -mode;
                            break;
                    }
                } while (chon != BACK);
                break;
            
            /*Menu chức năng 3*/
            case '3':
                do
                {
                    xoaManHinh();
                    if(mode == VN_US) {
                        menuChucNang3VN();
                    } else {
                        menuChucNang3US();
                    }

                    chon = _getch();
                    switch (chon)
                    {
                        double c;
                        // 3.1 F -> C && C -> F
                        case '1':
                            double f;
                            if(mode == VN_US) {
                                cout << "Nhap do C: ";
                                cin >> c;
                                cout << "Do F: " << celsiusToFahrenheit(c) << endl;
                            } else {
                                cout << "Enter degress F: ";
                                cin >> f;
                                cout << "Do C: " << fahrenheitToCelsius(f) << endl;
                            }
                            tamDung();
                            break;

                        // 3.2 C -> K && K -> C
                        case '2':
                            double k;
                            if(mode == VN_US) {
                                cout << "Nhap do C: ";
                                cin >> c;
                                cout << "Do K: " << celsiusToKenvin(c) << endl;
                            } else {
                                cout << "Enter degress k: ";
                                cin >> k;
                                cout << "Do C: " << kenvinToCelsius(k) << endl;
                            }
                            tamDung();
                            break;

                        // VN -> US && US -> VN
                        case TAB:
                            mode = -mode;
                            break;
                    }
                } while (chon != BACK);// Press 0 to back
                break;

            // VN -> US && US -> VN
            case TAB:
                mode = -mode;
                break;
        }
    } while (chon != ESC);// Press key ESC to exit

    return 0;
}

void xoaManHinh() {
    system("cls");
}

void tamDung() {
    system("pause");
}

/* MENU CHÍNH */
// Việt
void menuChucNangVN() {
    cout << "1. Doi don vi do chieu dai" << endl;
    cout << "2. Doi don vi do khoi luong" << endl;
    cout << "3. Doi don vi do nhiet do" << endl;
    cout << "Nhan ESC de thoat" << endl;
}

// Mĩ
void menuChucNangUS() {
    cout << "1. Convert length units" << endl;
    cout << "2. Change the unit of mass measurement" << endl;
    cout << "3. Change the unit of temperature measurement" << endl;
    cout << "Press key ESC to exit" << endl;
}

/* Menu Cấp 1 */
// Việt
void menuChucNang1VN() {
    cout << "1. Cm -> inch" << endl;
    cout << "2. Dm -> foot" << endl;
    cout << "3. M -> yard" << endl;
    cout << "4. Km -> mile" << endl;
    cout << "Nhan 0 de quay lai" << endl;
}

// Mĩ
void menuChucNang1US() {
    cout << "1. Inch -> cm" << endl;
    cout << "2. Foot -> dm" << endl;
    cout << "3. Yard -> m" << endl;
    cout << "4. Mile -> km" << endl;
    cout << "Press key 0 to back" << endl;
}

/* Menu Cấp 2 */
// Việt
void menuChucNang2VN() {
    cout << "1. Gr -> ounce" << endl;
    cout << "2. Kg -> pound" << endl;
    cout << "3. Tan -> ton" << endl;
    cout << "Nhan 0 de quay lai" << endl;
}

// Mĩ
void menuChucNang2US() {
    cout << "1. Ounce -> gr" << endl;
    cout << "2. Pound -> kg" << endl;
    cout << "3. Ton -> tan" << endl;
    cout << "Press key 0 to back" << endl;
}

/* Menu Cấp 3 */
// Việt
void menuChucNang3VN() {
    cout << "1. Celsius (C) -> Fahrenheit (F)" << endl;
    cout << "2. Celsius (C) -> Kenvin (K)" << endl;
    cout << "Nhan 0 de quay lai" << endl;
}

// Mĩ
void menuChucNang3US() {
    cout << "1. Fahrenheit (F) -> Celsius (C)" << endl;
    cout << "2. Kenvin (K) -> Celsius (C)" << endl;
    cout << "Press key 0 to back" << endl;
}

/* Các chức năng chuyển đổi của Menu cấp 1 */
// Việt sang Mĩ
double cmToInch(double cm) {
    return cm / 2.54;
}

double dmToFoot(double dm) {
    return dm / 3.048;
}

double mToYard(double m) {
    return m / 0.9144;
}

double kmToMile(double km) {
    return km / 1.609344;
}

// Mĩ sang Việt
double inchToCm(double inch) {
    return inch * 2.54; // 1 inch = 2.54 cm
}

double footToDm(double foot) {
    return foot * 3.048; // 1 foot = 3.048 dm
}

double yardToM(double yard) {
    return yard * 0.9144; // 1 yard = 0.9144 m
}

double mileToKm(double mile) {
    return mile * 1.609344; // 1 mile = 1.609344 km
}

/* Các chức năng chuyển đổi của Menu cấp 2 */
// Việt sang Mĩ
double grToOunce(double gr) {
    return gr / 28.3495231;
}

double kgToPound(double kg) {
    return kg / 0.45359237;
}

double tanToTon(double tan) {
    return tan / 18.14369;
}

// Mĩ sang Việt
double ounceToGr(double ounce) {
    return ounce * 28.3495231; // 1 ounce = 28.3495231 gr
}

double poundToKg(double pound) {
    return pound * 0.45359237; // 1 pound = 0.45359237 kg
}

double tonToTan(double ton) {
    return ton * 18.14369; // 1 ton = 18.14369 tấn
}

/* Các chức năng chuyển đổi của Menu cấp 3 */
// Việt sang Mĩ
double celsiusToFahrenheit(double c) {
    return 9.0/5 * c + 32;
}

double celsiusToKenvin(double c) {
    return c + 273.15;
}

// Mĩ sang Việt
double fahrenheitToCelsius(double f) {
    return 5.0/9 * (f - 32); // 1 C = 5/9 * (f-32)
}

double kenvinToCelsius(double k) {
    return k - 273.15; // 1 C = k - 273.15
}