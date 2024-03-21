#include <iostream>
using namespace std;

double hitungluas(double jari_jari) {
    return 3.14 * jari_jari * jari_jari;
}

void tampilluas(double luas) {
    cout << "Luas lingkaran adalah: " << luas << endl;
}

int main() {
    double jari_jari;
    cout << "Masukkan jari-jari lingkaran: ";
    cin >> jari_jari;

    double luas = hitungluas(jari_jari);

    tampilluas(luas);

    return 0;
}