#include <iostream>
#include <thread>
#include <chrono>

// using namespace std;

void jeda(int detik) {
    std::this_thread::sleep_for(std::chrono::seconds(detik));
}

struct info_transfer {
    int tujuan_saldo;
    int jumlah_uang;
};

struct akun {
    std::string username;
    std::string password;
    int tempat_setor[100] = {0};
    info_transfer transfer[100];
};

int input_jumlah_uang(int *jumlah_uang) {
    std::cin.ignore();
    if (*jumlah_uang <= 0 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cout << "Jumlah Uang harus berupa angka positif.\n";
        return 0;
    }
    return *jumlah_uang;
}

void jumlah_saldo(int saldo) {
    std::cout << "===========================\n";
    std::cout << "Jumlah Saldo Anda Saat Ini: " << saldo << std::endl;
    std::cout << "===========================\n";
    jeda(2);
}

void setor_uang(int &saldo, int jumlah_uang) {
    saldo += jumlah_uang;
    std::cout << "===========================\n";
    std::cout << "Setor Uang Berhasil. Saldo Anda Sekarang: " << saldo << std::endl;
    std::cout << "===========================\n";
    jeda(2);
}

void penarikan_uang(int &saldo, int jumlah_uang) {
    if (jumlah_uang <= saldo) {
        saldo -= jumlah_uang;
        std::cout << "=============================================\n";
        std::cout << "Penarikan Uang Berhasil. Saldo Anda Sekarang: " << saldo << std::endl;
        std::cout << "=============================================\n";
        jeda(2);
    } else {
        std::cout << "===========================\n";
        std::cout << "Saldo Anda Tidak Mencukupi.\n";
        std::cout << "===========================\n";
        jeda(2);
    }
}

void transfer_uang(int &saldo, info_transfer transfer[], int &jumlah_transfer, int jumlah_uang) {
    if (jumlah_uang <= saldo) {
        saldo -= jumlah_uang;
        int tujuan_saldo;
        std::cout << "Masukkan Nomor Rekening Tujuan: ";
        std::cin >> tujuan_saldo;
        if (tujuan_saldo >= 1 && tujuan_saldo <= 20) {
            transfer[jumlah_transfer].tujuan_saldo = tujuan_saldo;
            transfer[jumlah_transfer].jumlah_uang = jumlah_uang;
            jumlah_transfer++;

            std::cout << "=========================================\n";
            std::cout << "Transfer Berhasil. Saldo Anda Sekarang: " << saldo << std::endl;
            std::cout << "=========================================\n";
            jeda(2);
        } else {
            std::cout << "Tujuan Transfer Tidak Ada\n";
            jeda(2);
        }
    } else {
        std::cout << "Saldo Anda tidak mencukupi untuk transfer ini.\n";
        jeda(2);
    }
}