#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void jeda(int detik) {
    this_thread::sleep_for(chrono::seconds(detik));
}

int main() {
    int pilihan = 0;
    cout << "==========================\n";
    cout << "[1] Detail Kartu Kredit\n";
    cout << "[2] Sort Dari Besar ke Kecil\n";
    cout << "[3] Sort Nama Pengguna\n";
    cout << "==========================\n";
}