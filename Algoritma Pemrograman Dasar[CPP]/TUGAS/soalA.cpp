#include <iostream>
#include <cmath>

using namespace std;

void tentukan_segitiga(double sisi1, double sisi2, double sisi3) {
    if (sisi1 + sisi2 > sisi3 && sisi1 + sisi3 > sisi2 && sisi2 + sisi3 > sisi1) {
        if (sisi1 == sisi2 && sisi1 == sisi3) {
            cout << "Segitiga sama sisi\n";
        } else if (sisi1 == sisi2 || sisi1 == sisi3 || sisi2 == sisi3) {
            cout << "Segitiga sama kaki\n";
        } else if (pow(sisi1, 2) + pow(sisi2, 2) == pow(sisi3, 2) || 
                   pow(sisi1, 2) + pow(sisi3, 2) == pow(sisi2, 2) || 
                   pow(sisi2, 2) + pow(sisi3, 2) == pow(sisi1, 2)) {
            cout << "Segitiga siku-siku\n";
        } else {
            cout << "Segitiga sembarang\n";
        }
    } else {
        cout << "Bukan segitiga\n";
    } 
}

int main() {
    double sisi1, sisi2, sisi3;
    cout << "Masukkan panjang sisi segitiga:\n";
    cout << "Sisi 1: ";
    cin >> sisi1;
    cout << "Sisi 2: ";
    cin >> sisi2;
    cout << "Sisi 3: ";
    cin >> sisi3;

    tentukan_segitiga(sisi1, sisi2, sisi3);

    return 0;
}
