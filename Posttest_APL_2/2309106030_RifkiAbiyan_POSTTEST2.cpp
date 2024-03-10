#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

void jeda(int detik) {
    this_thread::sleep_for(chrono::seconds(detik));
}

int input_jumlah_uang() {
    int jumlah;
    while (!(cin >> jumlah) || jumlah <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Jumlah uang harus berupa angka positif! Silakan masukkan kembali: Rp ";
        system("clear");
        // system("cls");
    }
    return jumlah;
}

void jumlah_saldo(int saldo) {
    cout << "--------------------------\n";
    cout << "Jumlah Saldo Anda Saat Ini: " << saldo << endl;
    cout << "--------------------------\n";
    jeda(2);
}

void setor_uang(int &saldo, int jumlah_uang) {
    saldo += jumlah_uang;
    cout << "------------------------------------------\n";
    cout << "Uang Berhasil Disetor. Saldo Anda Sekarang: " << saldo << endl;
    cout << "------------------------------------------\n";
    jeda(2);
}

void penarikan_uang(int &saldo, int jumlah_uang) {
    if(jumlah_uang <= saldo) {
        saldo -= jumlah_uang;
        cout << "-------------------------------------------\n";
        cout << "Penarikan Uang Berhasil. Saldo Anda Sekarang: " << saldo << endl;
        cout << "-------------------------------------------\n";
        jeda(2);
    } else {
        cout << "----------------------\n";
        cout << "Saldo Tidak Mencukupi!\n";
        cout << "----------------------\n";
        jeda(1);
    }
}

void transfer_uang(int &saldo, int &tujuan_saldo, int jumlah_uang) {
    if(jumlah_uang <= saldo) {
        saldo -= jumlah_uang;
        tujuan_saldo += jumlah_uang;
        cout << "--------------------------------------\n";
        cout << "Transfer Berhasil. Saldo Anda Sekarang: " << saldo << endl;
        cout << "--------------------------------------\n";
        jeda(2);
    }
}

bool login(){
    string username = "Rifki Abiyan";
    string input_username;
    string password = "2309106030";
    string input_password;
    int percobaan = 3;

    while(percobaan > 0){
        system("clear");
        // system("cls");
        cout << "Masukkan username: ";
        getline(cin, input_username);
        if(input_username.empty()){
            cout << "Input Username Tidak Boleh Kosong!\n";
            percobaan--;
            if(percobaan > 0) {
                cout << "Tekan Enter Untuk Mencoba Lagi...";
                cin.ignore(); 
                cin.get();    
                continue;
            } 
            else {
                return false;
            }
        }

        cout << "Masukkan password: ";
        cin >> input_password;
        cin.ignore(); 
        if(input_password.empty()){
            cout << "Input Password Tidak Boleh Kosong!\n";
            percobaan--;
            if(percobaan > 0) {
                cout << "Tekan Enter Untuk Mencoba Lagi...";
                cin.ignore(); 
                cin.get();    
                continue;
            } 
            else {
                return false;
            }
        }

        if(input_username == username && input_password == password){
            return true;
        }
        else{
            percobaan--;
            cout << "Informasi Login Anda Salah!\n";
            if(percobaan > 0){
                cout << "Tekan Enter (2 kali) Untuk Mencoba Lagi...";
                cin.ignore();
                cin.get();
            }
        }
    }   
    return false;
}

int main() {
    bool status = login();

    if(!status){
        system("clear");
        // system("cls");
        cout << "==================================\n";
        cout << "Anda Melebihi 3 Kali Percobaan!\n";
        cout << "==================================\n";
        return 0;
    }
    else{
        cout << "===============\n";
        cout << "Login Berhasil!\n";
        cout << "===============\n";
        jeda(1);
    }
    int pilihan, jumlah_uang, tujuan;
    int saldoku = 0;
    int tempat_setor[100] = {0};

    do {
        system("clear");
        // system("cls");
        cout << "\nMesin ATM\n";
        cout << "====================\n";
        cout << "[1] Setor Tunai\n";
        cout << "[2] Lihat Saldo\n";
        cout << "[3] Penarikan Tunai\n";
        cout << "[4] Transfer Tunai\n";
        cout << "[5] Keluar\n";
        cout << "====================\n";   
        cout << "Pilih [1-5]: ";

        while (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pilihan harus berupa angka! Silakan masukkan kembali: ";
            system("clear");
            // system("cls");
        }

        switch(pilihan) {
            case 1:
                cout << "Masukkan Jumlah Uang Yang Ingin Disetor:Rp ";
                jumlah_uang = input_jumlah_uang();
                setor_uang(saldoku, jumlah_uang);
                break;
            case 2:
                jumlah_saldo(saldoku);
                break;
            case 3:
                cout << "Masukkan Jumlah Uang Yang Ingin Ditarik:Rp ";
                jumlah_uang = input_jumlah_uang(); 
                penarikan_uang(saldoku, jumlah_uang);
                break;
            case 4:
                cout << "Masukkan Jumlah Uang Yang Ingin Ditransfer:Rp ";
                jumlah_uang = input_jumlah_uang(); 
                cout << "Pilih Tujuan Transfer (1 - 20): ";

                while (!(cin >> tujuan)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Pilihan harus berupa angka! Silakan masukkan kembali: ";
                    system("clear");
                    // system("cls");
                }

                if(tujuan >= 1 && tujuan <= 20) {
                    transfer_uang(saldoku, tempat_setor[tujuan - 1], jumlah_uang);
                } else {
                    cout << "Tujuan Transfer Tidak Ada\n";
                    jeda(2);
                }
                break;
            case 5:
                system("clear");
                cout << "==================================\n";
                cout << "Terima Kasih Telah Menggunakan ATM\n";
                cout << "==================================\n";
                break;
            default:
                system("clear");
                cout << "===========================================\n";
                cout << "Pilihan Anda Salah, Pilih Menu Yang Sesuai.\n";
                cout << "===========================================\n";
        }
    } while(pilihan != 5);
    return 0;
}