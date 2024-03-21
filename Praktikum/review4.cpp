//RIfki Abiyan
//2309106030
//A2 2023
#include <iostream>
#include <string>
using namespace std;

struct Balok {
    double panjang;
    double lebar;
    double tinggi;
};

double hitung_volume(Balok balok) {
    return balok.panjang * balok.lebar * balok.tinggi;
}

int main() {
    Balok balok;
    cout << "Masukkan Panjang Balok: ";
    cin >> balok.panjang;
    cout << "Masukkan Lebar Balok: ";
    cin >> balok.lebar;
    cout << "Masukkan Tinggi Balok: ";
    cin >> balok.tinggi;

    double volume = hitung_volume(balok);
        cout << "Volume Balok Adalah: " << volume << endl;
        return 0;
    }
