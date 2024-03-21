#include <iostream>
using namespace std;

double hitung_volume_balok(double panjang, double lebar, double tinggi) {
    return panjang * lebar * tinggi;
}

int main() {
    double panjang, lebar, tinggi;

    cout << "Masukkan Panjang Balok: ";
    cin >> panjang;

    cout << "Masukkan Lebar Balok: ";
    cin >> lebar;

    cout << "Masukkan Tinggi Balok: ";
    cin >> tinggi;

    double volume = hitung_volume_balok(panjang, lebar, tinggi);
    cout << "Volume Balok Adalah: " << volume << endl;

    return 0;
}