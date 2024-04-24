#include <iostream>

bool login() {
    akun rifki;
    rifki.username = "rifki abiyan"; // Diubah menjadi case sensitive
    rifki.password = "2309106030";
    std::string input_username;
    std::string input_password;
    int percobaan = 3;

    while (percobaan > 0) {
        system("clear");
        // system("cls");
        std::cout << "Masukkan Username Anda: ";
        getline(std::cin, input_username);

        input_username.erase(0, input_username.find_first_not_of(" "));// untuk menghilangkan spasi sebelum dan sesudah username
        input_username.erase(input_username.find_last_not_of(" ") + 1);

        if (input_username.empty()) {
            std::cout << "Username Tidak Boleh Kosong.\n";
            percobaan--;
            if (percobaan > 0) {
                std::cout << "Tekan Enter Untuk Mencoba Lagi...";
                std::cin.ignore();
                std::cin.get();
                continue;
            } else {
                return false;
            }
        }
        std::cout << "Masukkan Password Anda: ";
        getline(std::cin, input_password);

        input_password.erase(0, input_password.find_first_not_of(" "));// untuk menghilangkan spasi sebelum dan sesudah password
        input_password.erase(input_password.find_last_not_of(" ") + 1);

        if (input_password.empty()) {
            std::cout << "Password Tidak Boleh Kosong.\n";
            percobaan--;
            if (percobaan > 0) {
                std::cout << "Tekan Enter Untuk Mencoba Lagi...";
                std::cin.ignore();
                std::cin.get();
                continue;
            } else {
                return false;
            }
        }
        if (input_username == rifki.username && input_password == rifki.password) {
            return true;
        } else {
            std::cout << "Informasi Login Anda Salah.\n";
            percobaan--;
            if (percobaan > 0) {
                std::cout << "Tekan Enter (2 kali) Untuk Mencoba Lagi...";
                std::cin.ignore();
                std::cin.get();
            }
        }
    }
    return false;
}