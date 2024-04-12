#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cctype>

using namespace std;
using namespace this_thread;
using namespace chrono;

void jeda(int detik) {
    sleep_for(seconds(detik));
}

struct info_transfer {
    int tujuan_saldo;
    int jumlah_uang;
};

struct akun {
    string username;
    string password;
    int tempat_setor[100] = {0};
    info_transfer transfer[100];
};

int input_jumlah_uang(int *jumlah_uang) {
    cin.ignore();
    if (*jumlah_uang <= 0 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Jumlah Uang harus berupa angka positif.\n";
        return 0;
    }
    return *jumlah_uang;
}

void jumlah_saldo(int saldo) {
    cout << "===========================\n";
    cout << "Jumlah Saldo Anda Saat Ini: " << saldo << endl;
    cout << "===========================\n";
    jeda(2);
}

void setor_uang(int &saldo, int jumlah_uang) {
    saldo += jumlah_uang;
    cout << "===========================\n";
    cout << "Setor Uang Berhasil. Saldo Anda Sekarang: " << saldo << endl;
    cout << "===========================\n";
    jeda(2);
}

void penarikan_uang(int &saldo, int jumlah_uang) {
    if (jumlah_uang <= saldo) {
        saldo -= jumlah_uang;
        cout << "=============================================\n";
        cout << "Penarikan Uang Berhasil. Saldo Anda Sekarang: " << saldo << endl;
        cout << "=============================================\n";
        jeda(2);
    } else {
        cout << "===========================\n";
        cout << "Saldo Anda Tidak Mencukupi.\n";
        cout << "===========================\n";
        jeda(2);
    }
}

void transfer_uang(int &saldo, info_transfer transfer[], int &jumlah_transfer, int jumlah_uang) {
    if (jumlah_uang <= saldo) {
        saldo -= jumlah_uang;
        int tujuan_saldo;
        cout << "Masukkan Nomor Rekening Tujuan: ";
        cin >> tujuan_saldo;
        if (tujuan_saldo >= 1 && tujuan_saldo <= 20) {
            transfer[jumlah_transfer].tujuan_saldo = tujuan_saldo;
            transfer[jumlah_transfer].jumlah_uang = jumlah_uang;
            jumlah_transfer++;

            cout << "=========================================\n";
            cout << "Transfer Berhasil. Saldo Anda Sekarang: " << saldo << endl;
            cout << "=========================================\n";
            jeda(2);
        } else {
            cout << "Tujuan Transfer Tidak Ada\n";
            jeda(2);
        }
    } else {
        cout << "Saldo Anda tidak mencukupi untuk transfer ini.\n";
        jeda(2);
    }
}

bool login() {
    akun rifki;
    rifki.username = "rifki abiyan"; // Diubah menjadi case sensitive
    rifki.password = "2309106030";
    string input_username;
    string input_password;
    int percobaan = 3;

    while (percobaan > 0) {
        system("clear");
        // system("cls");
        cout << "Masukkan Username Anda: ";
        getline(cin, input_username);

        input_username.erase(0, input_username.find_first_not_of(" "));// untuk menghilangkan spasi sebelum dan sesudah username
        input_username.erase(input_username.find_last_not_of(" ") + 1);

        if (input_username.empty()) {
            cout << "Username Tidak Boleh Kosong.\n";
            percobaan--;
            if (percobaan > 0) {
                cout << "Tekan Enter Untuk Mencoba Lagi...";
                cin.ignore();
                cin.get();
                continue;
            } else {
                return false;
            }
        }
        cout << "Masukkan Password Anda: ";
        getline(cin, input_password);

        input_password.erase(0, input_password.find_first_not_of(" "));// untuk menghilangkan spasi sebelum dan sesudah password
        input_password.erase(input_password.find_last_not_of(" ") + 1);

        if (input_password.empty()) {
            cout << "Password Tidak Boleh Kosong.\n";
            percobaan--;
            if (percobaan > 0) {
                cout << "Tekan Enter Untuk Mencoba Lagi...";
                cin.ignore();
                cin.get();
                continue;
            } else {
                return false;
            }
        }
        if (input_username == rifki.username && input_password == rifki.password) {
            return true;
        } else {
            cout << "Informasi Login Anda Salah.\n";
            percobaan--;
            if (percobaan > 0) {
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
    if (!status) {
        system("clear");
        cout << "===============================\n";
        cout << "Anda Melebihi 3 Kali Percobaan.\n";
        cout << "===============================\n";
        return 0;
    } else {
        cout << "===============================\n";
        cout << "Login Berhasil, Selamat Datang.\n";
        cout << "===============================\n";
        jeda(2);
    }
    int pilihan, jumlah_uang, tujuan, jumlah;
    int saldoku = 0;
    info_transfer tempat_setor[100];
    int jumlah_transfer = 0;

    do {
        system("clear");
        // system("cls");
        cout << "\nMESIN ATM\n";
        cout << "====================\n";
        cout << "[1] Setor Tunai\n";
        cout << "[2] Lihat Saldo\n";
        cout << "[3] Penarikan Tunai\n";
        cout << "[4] Transfer Tunai\n";
        cout << "[5] Keluar\n";
        cout << "====================\n";
        cout << "Silakan Pilih [1-5]: ";

        while (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pilihan Harus Berupa Angka. Silakan Dicoba Lagi: ";
            system("clear");
            // system("cls");
        }
        switch (pilihan) {
            case 1:
                cout << "Masukkan Jumlah Uang Yang Ingin Disetor: Rp ";
                cin >> jumlah;
                jumlah_uang = input_jumlah_uang(&jumlah);
                setor_uang(saldoku, jumlah_uang);
                break;
            case 2:
                jumlah_saldo(saldoku);
                break;
            case 3:
                cout << "Masukkan Jumlah Uang Yang Ingin Ditarik: Rp ";
                cin >> jumlah;
                jumlah_uang = input_jumlah_uang(&jumlah);
                penarikan_uang(saldoku, jumlah_uang);
                break;
            case 4:
                cout << "Masukkan Jumlah Uang Yang Ingin Ditransfer: Rp ";
                cin >> jumlah;
                jumlah_uang = input_jumlah_uang(&jumlah);

                while (true) {
                    cout << "Silakan Pilih Tujuan Transfer (1 - 100): ";

                    while (!(cin >> tujuan)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Pilihan Harus Berupa Angka. Silakan Dicoba lagi: ";
                        system("clear");
                    }
                    if (tujuan >= 1 && tujuan <= 20) {
                        transfer_uang(saldoku, tempat_setor, jumlah_transfer, jumlah_uang);
                        break;
                    } else {
                        cout << "Tujuan Transfer Tidak Ada\n";
                        jeda(2);
                    }
                }
                break;
            case 5:
                system("clear");
                // system("cls");
                cout << "==================================\n";
                cout << "Terima Kasih Telah Menggunakan ATM\n";
                cout << "==================================\n";
                break;
            default:
                system("clear");
                // system("cls");
                cout << "===========================================\n";
                cout << "Pilihan Anda Salah, Pilih Menu Yang Sesuai.\n";
                cout << "===========================================\n";
        }
    } while (pilihan != 5);
    return 0;
}
