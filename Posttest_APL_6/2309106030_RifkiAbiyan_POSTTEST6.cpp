#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cctype>
#include <limits>       

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
    string nama_bank;
    int saldo_nasabah;
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

void bubble_sort(string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].compare(arr[j + 1]) < 0) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion_sort(string arr[], int n) {
    for (int i = 1; i < n; ++i) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].compare(key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int interpolation_search(string arr[], int n, string key) {
    insertion_sort(arr, n);
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (arr[high] == arr[low]) {
            return (key == arr[low]) ? low : -1;
        }
        double pos = low + ((double)(high - low) / (arr[high][0] - arr[low][0])) * (key[0] - arr[low][0]);
        int intPos = static_cast<int>(pos);
        if (arr[intPos] == key) {
            return intPos;
        }
        if (arr[intPos] < key) {
            low = intPos + 1;
        } else {
            high = intPos - 1;
        }
    }
    return -1;
}

int binary_search(string arr[], int n, string key) {
    bubble_sort(arr, n);
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid].compare(key) < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

bool login(akun accounts[], int n) {
    string input_username;
    string input_password;
    int percobaan = 3;

    while (percobaan > 0) {
        system("clear");
        cout << "Masukkan Username Anda: ";
        getline(cin, input_username);

        input_username.erase(0, input_username.find_first_not_of(" "));
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

        input_password.erase(0, input_password.find_first_not_of(" "));
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

        for (int i = 0; i < n; ++i) {
            if (input_username == accounts[i].username && input_password == accounts[i].password) {
                return true;
            }
        }

        cout << "Informasi Login Anda Salah.\n";
        percobaan--;
        if (percobaan > 0) {
            cout << "Tekan Enter (2 kali) Untuk Mencoba Lagi...";
            cin.ignore();
            cin.get();
        }
    }
    return false;
}

int main() {
    akun accounts[4]; // Define multiple user accounts
    accounts[0].username = "rifki abiyan";
    accounts[0].password = "2309106030";
    accounts[0].nama_bank = "Mandiri";
    accounts[0].saldo_nasabah = 20000000;
    accounts[1].username = "arya aji wicaksana";
    accounts[1].password = "2309106150";
    accounts[1].nama_bank = "BNI";
    accounts[1].saldo_nasabah = 30000000;
    accounts[2].username = "genta maheswara";
    accounts[2].password = "2309106151";
    accounts[2].nama_bank = "BRI";
    accounts[2].saldo_nasabah = 40000000;
    accounts[3].username = "ridhan bagaskara";
    accounts[3].password = "2309106152";
    accounts[3].nama_bank = "BCA";
    accounts[3].saldo_nasabah = 50000000;

    int pilihan, jumlah_uang, tujuan, jumlah;
    int saldoku = 0; 
    info_transfer tempat_setor[100];
    int jumlah_transfer = 0;

    bool status = login(accounts, 4);
    if (!status) {
        system("clear");
        cout << "===============================\n";
        cout << "Anda Melebihi 3 Kali Percobaan.\n";
        cout << "===============================\n";
        return 0;
    } else {
        int userIndex = -1;
        string input_username;
        for (int i = 0; i < 4; ++i) {
            if (accounts[i].username == input_username) {
                userIndex = i;
                break;
            }
        }
        if (userIndex != -1) {
            saldoku = accounts[userIndex].saldo_nasabah;
        }

        cout << "===============================\n";
        cout << "Login Berhasil, Selamat Datang.\n";
        cout << "===============================\n";
        jeda(2);
    }

    string nama_banks[] = {"Mandiri", "BNI", "BRI", "BCA", "CIMB"};
    int bankCount = sizeof(nama_banks) / sizeof(nama_banks[0]);

    do {
        system("clear");
        cout << "\nMESIN ATM\n";
        cout << "====================\n";
        cout << "[0] Keluar\n";
        cout << "[1] Setor Tunai\n";
        cout << "[2] Lihat Saldo\n";
        cout << "[3] Penarikan Tunai\n";
        cout << "[4] Transfer Tunai\n";
        cout << "[5] Sort Nama Nasabah (Descending)\n";
        cout << "[6] Sort Jumlah Saldo Nasabah (Ascending)\n";
        cout << "[7] Sort Nama Bank Nasabah (Ascending)\n";
        cout << "[8] Interpolation Search Ascending\n";
        cout << "[9] Binary Search Descending\n";
        cout << "====================\n";
        cout << "Silakan Pilih [0-9]: ";

        while (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pilihan Harus Berupa Angka. Silakan Dicoba Lagi: ";
            system("clear");
        }
        switch (pilihan) {
            case 0:
                system("clear");
                cout << "==================================\n";
                cout << "Terima Kasih Telah Menggunakan ATM\n";
                cout << "==================================\n";
                break;
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
            case 5: {
                int n = sizeof(accounts) / sizeof(accounts[0]);
                string usernames[n];
                for (int i = 0; i < n; ++i) {
                    usernames[i] = accounts[i].username;
                }
                bubble_sort(usernames, n);
                cout << "Sorted Nama Nasabah (Descending): ";
                for (int i = 0; i < n; ++i) {
                    cout << usernames[i] << ", ";
                }
                cout << endl;
                jeda(3);
                break;
            }
            case 6: {
                int balances[] = {accounts[0].saldo_nasabah, accounts[1].saldo_nasabah, accounts[2].saldo_nasabah, accounts[3].saldo_nasabah};
                string usernames[] = {accounts[0].username, accounts[1].username, accounts[2].username, accounts[3].username};
                int n = sizeof(balances) / sizeof(balances[0]);

                for (int i = 0; i < n - 1; ++i) {
                    for (int j = 0; j < n - i - 1; ++j) {
                        if (balances[j] > balances[j + 1]) {
                            swap(balances[j], balances[j + 1]);
                            swap(usernames[j], usernames[j + 1]);
                        }
                    }
                }

                cout << "Sorted Saldo Nasabah (Ascending):\n";
                for (int i = 0; i < n; ++i) {
                    cout << "Nasabah: " << usernames[i] << ", Saldo: " << balances[i] << endl;
                }
                jeda(3);
                break;
            }
            case 7: {
                string usernama_banks[4];
                for (int i = 0; i < 4; ++i) {
                    usernama_banks[i] = accounts[i].nama_bank;
                }
                insertion_sort(usernama_banks, 4);
                cout << "Sorted Nama Bank Nasabah (Ascending): ";
                for (int i = 0; i < 4; ++i) {
                    cout << usernama_banks[i] << " ";
                }
                cout << endl;
                jeda(3);
                break;
            }
            case 8: {
                string usernames[] = {accounts[0].username, accounts[1].username, accounts[2].username, accounts[3].username};
                int n = sizeof(usernames) / sizeof(usernames[0]);
                string key;
                cout << "Masukkan Nama Nasabah Yang Ingin Dicari: ";
                cin.ignore();
                getline(cin, key);
                insertion_sort(usernames, n);
                int index = interpolation_search(usernames, n, key);
                if (index != -1) {
                    cout << "Nasabah Ditemukan Diindex: " << index << endl;
                    jeda(3);
                } else {
                    cout << "Nasabah Tidak Ditemukan.\n";
                    jeda(3);
                }
                break;
            }
            case 9: {
                string usernames[] = {accounts[0].username, accounts[1].username, accounts[2].username, accounts[3].username};
                int n = sizeof(usernames) / sizeof(usernames[0]);
                string key;
                cout << "Masukkan Nama Nasabah Yang Ingin Dicari: ";
                cin.ignore();
                getline(cin, key);
                bubble_sort(usernames, n);
                int index = binary_search(usernames, n, key);
                if (index != -1) {
                    cout << "Nasabah Ditemukan Diindex: " << index << endl;
                    jeda(2);
                } else {
                    cout << "Nasabah Tidak Ditemukan.\n";
                    jeda(2);
                }
                break;
            }

            default:
                system("clear");
                cout << "===========================================\n";
                cout << "Pilihan Anda Salah, Pilih Menu Yang Sesuai.\n";
                cout << "===========================================\n";
        }
    } while (pilihan != 0);
    return 0;
}
