// // #include <iostream>

// // const int MAX_SIZE = 100;

// // class CRUDArray {
// // private:
// //     int arr[MAX_SIZE];
// //     int size;

// // public:
// //     CRUDArray() {
// //         size = 0;
// //     }

// //     // Create (Insert) operation
// //     void create(int value) {
// //         if (size < MAX_SIZE) {
// //             arr[size] = value;
// //             size++;
// //             std::cout << "Value " << value << " inserted successfully." << std::endl;
// //         } else {
// //             std::cerr << "Array is full. Cannot insert value." << std::endl;
// //         }
// //     }

// //     // Read operation
// //     void read() {
// //         std::cout << "Array elements: ";
// //         for (int i = 0; i < size; ++i) {
// //             std::cout << arr[i] << " ";
// //         }
// //         std::cout << std::endl;
// //     }

// //     // Update operation
// //     void update(int oldValue, int newValue) {
// //         bool found = false;
// //         for (int i = 0; i < size; ++i) {
// //             if (arr[i] == oldValue) {
// //                 arr[i] = newValue;
// //                 found = true;
// //                 std::cout << "Value " << oldValue << " updated to " << newValue << " successfully." << std::endl;
// //                 break;
// //             }
// //         }
// //         if (!found) {
// //             std::cerr << "Value " << oldValue << " not found. Cannot update." << std::endl;
// //         }
// //     }

// //     // Delete operation
// //     void del(int value) {
// //         bool found = false;
// //         for (int i = 0; i < size; ++i) {
// //             if (arr[i] == value) {
// //                 found = true;
// //                 for (int j = i; j < size - 1; ++j) {
// //                     arr[j] = arr[j + 1];
// //                 }
// //                 size--;
// //                 std::cout << "Value " << value << " deleted successfully." << std::endl;
// //                 break;
// //             }
// //         }
// //         if (!found) {
// //             std::cerr << "Value " << value << " not found. Cannot delete." << std::endl;
// //         }
// //     }
// // };

// // int main() {
// //     CRUDArray array;

// //     // Create
// //     array.create(10);
// //     array.create(20);
// //     array.create(30);

// //     // Read
// //     array.read();

// //     // Update
// //     array.update(20, 25);
// //     array.read();

// //     // Delete
// //     array.del(25);
// //     array.read();

// //     return 0;
// // }
// // #include <iostream>
// // #include <string>
// // #include <chrono>
// // #include <thread>
// // using namespace std;

// // void delay(int detik) {
// //     this_thread::sleep_for(chrono::seconds(detik));
// // }

// // const int maks_kostum = 10; 

// // struct status_kostum {
// //     string nama;
// //     bool tersedia;
// // };

// // status_kostum kostum[maks_kostum]; 
// // int jumlah_kostum = 0; 

// // void tambah_kostum(const string& nama) {
// //     if (jumlah_kostum < maks_kostum) {
// //         kostum[jumlah_kostum].nama = nama;
// //         kostum[jumlah_kostum].tersedia = true;
// //         jumlah_kostum++;
// //         cout << "Kostum berhasil ditambah.\n";
// //         delay(2);
// //     } else {
// //         cout << "Tidak bisa menambah kostum. Pesanannya penuh.\n";
// //         delay(2);
// //     }
// // }

// // void lihat_kostum() {
// //     cout << "Kostum:\n";
// //     for (int i = 0; i < jumlah_kostum; ++i) {
// //         cout << "Nama: " << kostum[i].nama << ", Tersedia: " << (kostum[i].tersedia ? "Yes" : "No") << "\n";
// //         delay(2);
// //     }
// // }

// // void ketersediaan_kostum(const string& nama, bool tersedia) {
// //     for (int i = 0; i < jumlah_kostum; ++i) {
// //         if (kostum[i].nama == nama) {
// //             kostum[i].tersedia = tersedia;
// //             cout << "Ketersediaan kostum berhasil diubah.\n";
// //             return;
// //         }
// //     }
// //     cout << "Kostum tidak ditemukan.\n";
// //     delay(2);
// // }

// // void hapus_kostum(const string& nama) {
// //     for (int i = 0; i < jumlah_kostum; ++i) {
// //         if (kostum[i].nama == nama) {
// //             // guna menggeser array untuk tidak kosong
// //             for (int j = i; j < jumlah_kostum - 1; ++j) {
// //                 kostum[j] = kostum[j + 1];
// //             }
// //             jumlah_kostum--;
// //             cout << "Kostum berhasil dihapus.\n";
// //             return;
// //         }
// //     }
// //     cout << "Kostum tidak ditemukan.\n";
// //     delay(2);
// // }

// // int main() {
// //     int pilihan;
// //     string nama;

// //     do {
// //         system("clear");
// //         cout << "\nMenu\n";
// //         cout << "------------------------\n";
// //         cout << "1. Tambah Kostum\n";
// //         cout << "2. Lihat Kostum\n";
// //         cout << "3. Ketersediaan Kostum\n";
// //         cout << "4. Hapus Kostum\n";
// //         cout << "5. Keluar\n";
// //         cout << "------------------------\n";
// //         cout << "Masukkan pilihan anda: ";
// //         cin >> pilihan;

// //         switch (pilihan) {
// //             case 1:
// //                 cout << "Masukkan nama kostum: ";
// //                 cin >> nama;
// //                 tambah_kostum(nama);
// //                 break;
// //             case 2:
// //                 lihat_kostum();
// //                 break;
// //             case 3:
// //                 lihat_kostum();
// //                 cout << "Masukkan nama kostum: ";
// //                 cin >> nama;
// //                 bool tersedia;
// //                 cout << "apakah tersedia? (1 = iya, 0 = tidak): ";
// //                 cin >> tersedia;
// //                 ketersediaan_kostum(nama, tersedia);
// //                 break;
// //             case 4:
// //                 lihat_kostum();
// //                 cout << "Masukkan nama kostum: ";
// //                 cin >> nama;
// //                 hapus_kostum(nama);
// //                 break;
// //             case 5:
// //                 cout << "Keluar...\n";
// //                 break;
// //             default:
// //                 cout << "pilihan tidak tersedia.\n";
// //         }
// //     } while (pilihan != 5);

// //     return 0;
// // }

// // #include <iostream>
// // using namespace std;

// // // Deklarasi class ATM
// // class ATM {
// // private:
// //     string nama;
// //     int saldo;
// // public:
// //     ATM(string nama, int saldo) {
// //         this->nama = nama;
// //         this->saldo = saldo;
// //     }

// //     void setorUang(int jumlah) {
// //         saldo += jumlah;
// //         cout << "Uang berhasil disetor. Saldo Anda sekarang: " << saldo << endl;
// //     }

// //     void lihatSaldo() {
// //         cout << "Saldo Anda saat ini: " << saldo << endl;
// //     }

// //     void tarikUang(int jumlah) {
// //         if (jumlah <= saldo) {
// //             saldo -= jumlah;
// //             cout << "Uang berhasil ditarik. Saldo Anda sekarang: " << saldo << endl;
// //         } else {
// //             cout << "Saldo tidak mencukupi" << endl;
// //         }
// //     }

// //     void transferUang(int jumlah, int &tujuan_saldo) {
// //         if (jumlah <= saldo) {
// //             saldo -= jumlah;
// //             tujuan_saldo += jumlah;
// //             cout << "Transfer berhasil. Saldo Anda sekarang: " << saldo << endl;
// //         } else {
// //             cout << "Saldo tidak mencukupi" << endl;
// //         }
// //     }

// //     int getSaldo() {
// //         return saldo;
// //     }
// // };

// // int main() {
// //     ATM user("User", 0);
// //     int tempatSetor[100] = {0}; // Array untuk menyimpan saldo uang di tempat tujuan transfer
// //     int opsi, jumlah, pilihan, tujuan;

// //     do {
// //         cout << "\n===== Menu ATM =====" << endl;
// //         cout << "1. Setor Uang" << endl;
// //         cout << "2. Lihat Saldo" << endl;
// //         cout << "3. Tarik Uang" << endl;
// //         cout << "4. Transfer Uang" << endl;
// //         cout << "5. Keluar" << endl;
// //         cout << "Pilih opsi: ";
// //         cin >> opsi;

// //         switch (opsi) {
// //             case 1:
// //                 cout << "Masukkan jumlah uang yang ingin disetor: ";
// //                 cin >> jumlah;
// //                 user.setorUang(jumlah);
// //                 break;
// //             case 2:
// //                 user.lihatSaldo();
// //                 break;
// //             case 3:
// //                 cout << "Masukkan jumlah uang yang ingin ditarik: ";
// //                 cin >> jumlah;
// //                 user.tarikUang(jumlah);
// //                 break;
// //             case 4:
// //                 cout << "Masukkan jumlah uang yang ingin ditransfer: ";
// //                 cin >> jumlah;
// //                 cout << "Pilih tujuan transfer (1 - 100): ";
// //                 cin >> tujuan;
// //                 if (tujuan >= 1 && tujuan <= 100) {
// //                     user.transferUang(jumlah, tempatSetor[tujuan - 1]);
// //                 } else {
// //                     cout << "Tujuan transfer tidak valid" << endl;
// //                 }
// //                 break;
// //             case 5:
// //                 cout << "Terima kasih telah menggunakan layanan ATM." << endl;
// //                 break;
// //             default:
// //                 cout << "Opsi tidak valid." << endl;
// //         }
// //     } while (opsi != 5);

// //     return 0;
// // }

// #include <iostream>
// using namespace std;

// // Fungsi untuk menampilkan saldo ATM
// void lihatSaldo(int saldo) {
//     cout << "Saldo Anda saat ini: " << saldo << endl;
// }

// // Fungsi untuk melakukan setor uang
// void setorUang(int &saldo, int jumlah) {
//     saldo += jumlah;
//     cout << "Uang berhasil disetor. Saldo Anda sekarang: " << saldo << endl;
// }

// // Fungsi untuk melakukan penarikan uang
// void tarikUang(int &saldo, int jumlah) {
//     if (jumlah <= saldo) {
//         saldo -= jumlah;
//         cout << "Uang berhasil ditarik. Saldo Anda sekarang: " << saldo << endl;
//     } else {
//         cout << "Saldo tidak mencukupi" << endl;
//     }
// }

// // Fungsi untuk mentransfer uang
// void transferUang(int &saldo, int &tujuan_saldo, int jumlah) {
//     if (jumlah <= saldo) {
//         saldo -= jumlah;
//         tujuan_saldo += jumlah;
//         cout << "Transfer berhasil. Saldo Anda sekarang: " << saldo << endl;
//     } else {
//         cout << "Saldo tidak mencukupi" << endl;
//     }
// }

// int main() {
//     int saldo_user = 0;
//     int tempatSetor[100] = {0}; // Array untuk menyimpan saldo uang di tempat tujuan transfer
//     int opsi, jumlah, tujuan;

//     do {
//         cout << "\n===== Menu ATM =====" << endl;
//         cout << "1. Setor Uang" << endl;
//         cout << "2. Lihat Saldo" << endl;
//         cout << "3. Tarik Uang" << endl;
//         cout << "4. Transfer Uang" << endl;
//         cout << "5. Keluar" << endl;
//         cout << "Pilih opsi: ";
//         cin >> opsi;

//         switch (opsi) {
//             case 1:
//                 cout << "Masukkan jumlah uang yang ingin disetor: ";
//                 cin >> jumlah;
//                 setorUang(saldo_user, jumlah);
//                 break;
//             case 2:
//                 lihatSaldo(saldo_user);
//                 break;
//             case 3:
//                 cout << "Masukkan jumlah uang yang ingin ditarik: ";
//                 cin >> jumlah;
//                 tarikUang(saldo_user, jumlah);
//                 break;
//             case 4:
//                 cout << "Masukkan jumlah uang yang ingin ditransfer: ";
//                 cin >> jumlah;
//                 cout << "Pilih tujuan transfer (1 - 100): ";
//                 cin >> tujuan;
//                 if (tujuan >= 1 && tujuan <= 100) {
//                     transferUang(saldo_user, tempatSetor[tujuan - 1], jumlah);
//                 } else {
//                     cout << "Tujuan transfer tidak valid" << endl;
//                 }
//                 break;
//             case 5:
//                 cout << "Terima kasih telah menggunakan layanan ATM." << endl;
//                 break;
//             default:
//                 cout << "Opsi tidak valid." << endl;
//         }
//     } while (opsi != 5);

//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>
// #include <limits>
// #include <chrono>
// #include <thread>

// using namespace std;

// void delay(int seconds) {
//     this_thread::sleep_for(chrono::seconds(seconds));
// }

// struct informasi_pribadi {
//     string nama;
//     string tanggal_lahir;
//     string alamat;
//     string no_telepon;
//     string no_ktp;
// };

// struct informasi_kartu_kredit {
//     string nama;
//     string no_kartu;
//     string tanggal_valid;
//     string cvv;
//     string limit;
// };

// struct informasi_pelamar {
//     string nama;
//     string usia;
//     string kartu_identitas;
//     string penghasilan;
// };

// void insertionSort(vector<informasi_pribadi>& arr) {
//     for (int i = 1; i < arr.size(); i++) {
//         informasi_pribadi key = arr[i];
//         int j = i - 1;
//         while (j >= 0 && arr[j].nama > key.nama) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
// }

// int binarySearch(const vector<informasi_pribadi>& arr, const string& key) {
//     int left = 0;
//     int right = arr.size() - 1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (arr[mid].nama == key)
//             return mid;
//         else if (arr[mid].nama < key)
//             left = mid + 1;
//         else
//             right = mid - 1;
//     }
//     return -1; // Not found
// }

// int main() {
//     int pilihan;
//     vector<informasi_pribadi> data_pribadi;
//     vector<informasi_pelamar> data_pelamar;
    
//     do {
//         system("clear");
//         cout << "=============| MENU |=============\n";
//         cout << "[1] Informasi Pemilik Kartu Kredit\n";
//         cout << "[2] Informasi Pelamar Kartu Kredit\n";
//         cout << "[3] Keluar\n";
//         cout << "=============| MENU |=============\n";
//         cout << "Silahkan Pilih(1/2/3): ";
        
//         while(!(cin >> pilihan)) {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             cout << "===========================\n";
//             cout << "Pilihan Harus Berupa Angka.\n";
//             cout << "===========================\n";
//             delay(2);
//             return main();
//         }

//         switch(pilihan) {
//             case 1: {
//                 system("clear");
//                 informasi_pribadi pemilik;
//                 cout << "Nama: ";
//                 cin >> pemilik.nama;
//                 cout << "Tanggal Lahir: ";
//                 cin >> pemilik.tanggal_lahir;
//                 cout << "Alamat: ";
//                 cin >> pemilik.alamat;
//                 cout << "No Telepon: ";
//                 cin >> pemilik.no_telepon;
//                 cout << "No KTP: ";
//                 cin >> pemilik.no_ktp;
//                 data_pribadi.push_back(pemilik);
//                 insertionSort(data_pribadi);
//                 break;
//             }
//             case 2: {
//                 system("clear");
//                 informasi_pelamar pelamar;
//                 cout << "Nama: ";
//                 cin >> pelamar.nama;
//                 cout << "Usia: ";
//                 cin >> pelamar.usia;
//                 cout << "Kartu Identitas: ";
//                 cin >> pelamar.kartu_identitas;
//                 cout << "Penghasilan: ";
//                 cin >> pelamar.penghasilan;
//                 data_pelamar.push_back(pelamar);
//                 break;
//             }
//             case 3:
//                 cout << "Terima Kasih Telah Menggunakan Program Ini.\n";
//                 delay(2);
//                 break;
//             default:
//                 system("clear");
//                 cout << "===========================================\n";
//                 cout << "Pilihan Anda Salah, Pilih Menu Yang Sesuai.\n";
//                 cout << "===========================================\n";
//                 delay(2);
//         }
//     } while (pilihan != 3);
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// struct informasi_pribadi {
//     string nama;
//     string tanggal_lahir;
//     string alamat;
//     string no_telepon;
//     string no_ktp;
// };

// // Function to print an array of informasi_pribadi
// void printArray(const informasi_pribadi arr[], int size) {
//     for (int i = 0; i < size; ++i) {
//         cout << "Nama: " << arr[i].nama << ", Tanggal Lahir: " << arr[i].tanggal_lahir << ", Alamat: " << arr[i].alamat
//              << ", No Telepon: " << arr[i].no_telepon << ", No KTP: " << arr[i].no_ktp << endl;
//     }
// }

// // Function to sort an array of informasi_pribadi by nama using selection sort
// void selectionSort(informasi_pribadi arr[], int size) {
//     for (int i = 0; i < size - 1; ++i) {
//         int minIndex = i;
//         for (int j = i + 1; j < size; ++j) {
//             if (arr[j].nama < arr[minIndex].nama) {
//                 minIndex = j;
//             }
//         }
//         swap(arr[i], arr[minIndex]);
//     }
// }

// int main() {
//     informasi_pribadi data[] = {
//         {"John Doe", "1990-01-01", "123 Main St", "123-456-7890", "12345"},
//         {"Alice Smith", "1985-05-15", "456 Elm St", "456-789-0123", "67890"},
//         {"Bob Johnson", "1978-11-20", "789 Oak St", "789-012-3456", "54321"}
//     };
//     int size = sizeof(data) / sizeof(data[0]);

//     cout << "Unsorted Data:" << endl;
//     printArray(data, size);

//     // Sorting the array
//     selectionSort(data, size);

//     cout << "\nSorted Data:" << endl;
//     printArray(data, size);

//     return 0;
// }

// #include <iostream>
// using namespace std;

// // Outer struct
// struct OuterStruct {
//     int outerData;
    
//     // Nested struct
//     struct InnerStruct {
//         int innerData;
//     };
// };

// int main() {
//     // Create an instance of the outer struct
//     OuterStruct outer;

//     // Assign values to the members of the outer struct
//     outer.outerData = 10;

//     // Create an instance of the nested struct
//     OuterStruct::InnerStruct inner;

//     // Assign values to the members of the nested struct
//     inner.innerData = 20;

//     // Access and print the values
//     cout << "Outer data: " << outer.outerData << endl;
//     cout << "Inner data: " << inner.innerData << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;
// typedef struct{
//     char nim[10];
//     string nama;
//     float nilai;
// }

// mahasiswa;

// int main(){
//     mahasiswa mhs;
//     cout << "Masukkan NIM : "; cin >> mhs.nim;
//     fflush(stdin);
//     cout << "Masukkan Nama : "; 
//     fflush(stdin); getline(cin, mhs.nama);
//     fflush(stdin);
//     cout << "Masukkan Nilai Akhir : "; cin >> mhs.nilai;
//     cout << "\nData yang diinputkan adalah : " << endl;
//     cout << "NIM : " << mhs.nim << endl;
//     cout << "Nama : " << mhs.nama << endl;
//     cout << "Nilai Akhir : " << mhs.nilai << endl;
// }