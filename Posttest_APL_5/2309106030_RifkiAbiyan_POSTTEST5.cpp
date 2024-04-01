#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cctype>

#define cls "clear"

using namespace std;
using namespace this_thread;
using namespace chrono;

void jeda(int detik) {
    sleep_for(seconds(detik));
}

struct akun {
    string username;
    string password;
};

bool login() {
    akun rifki;
    rifki.username = "rifki abiyan";
    rifki.password = "2309106030";
    string input_username;
    string input_password;
    int percobaan = 3;

    while(percobaan > 0) {
        system("clear");
        cout << "Masukkan Username Anda; ";
        getline(cin, input_username);

        if(input_username.empty()) {
            cout << "Usernama Tidak Boleh Kosong.\n";
            percobaan--;
            if(percobaan > 0) {
                cout << "Tekan Enter Untuk Mencoba Lagi...";
                cin.ignore();
                cin.get();
                continue;
            } else {
                return false;
            }
        }
    }
}

int main() {

}