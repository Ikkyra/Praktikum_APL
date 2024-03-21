#include <iostream>
using namespace std;

struct mahasiswa {
    string nama, nim;
    int nilai;
};

struct mahasiswa mhs[10];

int n = 0;

void create() {
    cout << "Nama Mahasiswa: ";cin.ignore(), getline(cin, mhs[n].nama);
    cout << "NIM Mahasiswa: ";cin.ignore(), cin >> mhs[n].nim;
    cout << "Nilai Mahasiswa: ";cin >> mhs[n].nilai;
    n++;
};

void read() {
    for (int i = 0; i < n; i++) {
        cout << "=====================\n";
        cout << "Nama Mahasiswa: " << mhs[i].nama << endl;
        cout << "NIM Mahasiswa: " << mhs[i].nim << endl;
        cout << "Nilai Mahasiswa: " << mhs[i].nilai << endl;
        cout << "=====================\n";
    }
};

void update() {
    string nim_update;
    cout << "Masukkan NIM Yang Ingin Diubah: ";cin >> nim_update;
    for(int i = 0; i < n; i++) {
        if(nim_update == mhs[i].nim) {
            try {
                while(true) {
                    cout << "Nama Mahasiswa: ";cin.ignore(), getline(cin, mhs[i].nama);
                    cout << "Nilai Mahasiswa: ";
                    if(!(cin >> mhs[i].nilai)) {
                        cin.clear();
                        cin.ignore();
                        cout << "Input Salah\n";
                        continue;
                    } else {
                        throw nim_update;
                    }
                }
            }
            catch(string a) {} 
            break;
        }
    }
};

void del() {
    string nim_delete;
    cout << "Masukkan NIM Yang Ingin Dihapus: ";cin >> nim_delete;
    for(int i = 0; i < n; i++) {
        if(nim_delete == mhs[i].nim) {
            for(int j = i; j < n; j++) {
                mhs[j] = mhs[j+1];
            }
            n--;
            break;
        }
    }
};

int main() {
    int pilihan;
    while(true) {
        cout << "MENU\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Ubah Data\n";
        cout << "4. Hapus Data\n";
        cout << "Pilih: "; cin >> pilihan;
        // switch(pilihan) {
        //     case 1:
        //         create();
        //         break;
        //     case 2:
        //         read();
        //         break;
        //     case 3:
        //         update();
        //         break;
        //     case 4:
        //         del();
        //         break;
        //     default:
        //         cout << "Pilihan Tidak Ada\n";
        // }
        if(pilihan == 1) {
            create();
        } else if(pilihan == 2) {
            read();
        } else if(pilihan == 3) {
            update();
        } else if(pilihan == 4) {
            del();
        } else {
            cout << "Pilihan Tidak Ada\n";
        }
    }
}