#include <iostream> 

#include "sort.cpp"
#include "search.cpp"
#include "login.cpp"
#include "atm.cpp"

int main() {
    bool status = login();
    if(!status) {
        system("clear");
        // system("cls");
        std::cout << "===============================\n";
        std::cout << "Anda Melebihi 3 Kali Percobaan.\n";
        std::cout << "===============================\n";
        return 0;
    } else {
        std::cout << "===============================\n";
        std::cout << "Login Berhasil, Selamat Datang.\n";
        std::cout << "===============================\n";
        jeda(2);
    }
    int pilihan, jumlah_uang, tujuan, jumlah;
    int saldoku = 0;
    info_transfer tempat_setor[100];
    int jumlah_transfer = 0;

    do {
        system("clear");
        // system("cls");
        std::cout << "=====================\n";
        std::cout << "====  MESIN ATM  ====\n";
        std::cout << "=====================\n";
        std::cout << "=[0] Keluar         =\n";
        std::cout << "=[1] Setor Saldo    =\n";
        std::cout << "=[2] Lihat Saldo    =\n";
        std::cout << "=[3] Tarik Saldo    =\n";
        std::cout << "=[4] Transfer Saldo =\n";
        std::cout << "=====================\n";
        std::cout << "Pilih Metode: ";
        std::cin >> pilihan;

        while(!(std::cin >> pilihan)) {
            std::cin.clear();
            std::cin.ignore(numeric<streamsize>::max(), '\n');
            std::cout << "Pilihan Harus Berupa Angka. Silakan Coba Lagi.";
            system("clear");
            system("cls");
        }

        switch(pilihan) {
            case 0:
                system("clear");
                // system("cls"):
                std::cout << "======================================\n";
                std::cout << "= Terima Kasih Telah Menggunakan ATM =\n";
                std::cout << "======================================\n";
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                system("clear");
                // system("cls");
                std::cout << "==============================================\n";
                std::cout << "= Pilihan Anda Salah, Pilih Menu Yang Sesuai =\n";
                std::cout << "==============================================\n";
        }
    } while(pilihan != 5);
    return 0;
}