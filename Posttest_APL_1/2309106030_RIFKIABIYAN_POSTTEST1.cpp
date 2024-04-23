#include <iostream>
#include <string>

using namespace std;

void konversi_rupiah(double idr, double& usd, double& eur, double& yen){
    usd = idr*0.000064;
    eur = idr*0.000059;
    yen = idr*0.0096;
};

void konversi_dollar(double usd, double& idr, double& eur, double& yen){
    idr = usd*15701;
    eur = usd*0.92;
    yen = usd*150.09;
};

void konversi_euro(double eur, double& idr, double& usd, double& yen){
    idr = eur*17043;
    usd = eur*1.09;
    yen = eur*162.93;
};

void konversi_yen(double yen, double& idr, double& usd, double& eur){
    idr = yen*104.61;
    usd = yen*0.0067;
    eur = yen*0.0061;
};

bool login(){
    string username = "Rifki Abiyan";
    string input_username;
    string password = "2309106030";
    string input_password;
    int percobaan = 3;

    while(percobaan > 0){
        system("clear");
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
        getline(cin, input_password);
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
                cout << "Tekan Enter Untuk Mencoba Lagi...";
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
        cout << "==================================\n";
        cout << "Anda Melebihi 3 Kali Percobaan!\n";
        cout << "==================================\n";
        return 0;
    }
    else{
        cout << "Login Berhasil!\n";
    }
    int pilihan;
    double jumlah_uang;

    do {
        cout << endl;
        cout << "======= Konversi Mata Uang =======\n";
        cout << "1. Konversi Rupiah ke Dollar, Euro, Yen\n";
        cout << "2. Konversi Dollar ke Rupiah, Euro, Yen\n";
        cout << "3. Konversi Euro ke Rupiah, Dollar, Yen\n";
        cout << "4. Konversi Yen ke Rupiah, Dollar, Euro\n";
        cout << "5. Keluar\n";
        cout << "==================================\n";
        cout << "Silakan Pilih: \n";
        cin >> pilihan;

        double idr, usd, eur, yen;

        switch(pilihan){
            case 1: 
                cout << "Masukkan Jumlah Uang Rupiah: ";
                cin >> jumlah_uang;
                konversi_rupiah(jumlah_uang, usd, eur, yen);
                

                system("clear");
                cout << "==================================\n";
                cout << "Dollar(usd): \n" << usd << endl;
                cout << "Euro(eur): \n" << eur << endl;
                cout << "Japanese Yen(yen): \n" << yen << endl;
                cout << "==================================\n";
                break;
            
            case 2: 
                cout << "Masukkan Jumlah Uang Dollar: ";
                cin >> jumlah_uang;
                konversi_dollar(jumlah_uang, idr, eur, yen);

                system("clear");
                cout << "==================================\n";
                cout << "Rupiah(idr): \n" << idr << endl;
                cout << "Euro(eur): \n" << eur << endl;
                cout << "Japanese Yen(yen): \n" << yen << endl;
                cout << "==================================\n";
                break;
            
            case 3: 
                cout << "Masukkan Jumlah Uang Euro: ";
                cin >> jumlah_uang;
                konversi_euro(jumlah_uang, idr, usd, yen);

                system("clear");
                cout << "==================================\n";
                cout << "Rupiah(idr): \n" << idr << endl;
                cout << "Dollar(usd): \n" << usd << endl;
                cout << "Japanese Yen(yen): \n" << yen << endl;
                cout << "==================================\n";
                break;
            
            case 4: 
                cout << "Masukkan Jumlah Uang Yen: ";
                cin >> jumlah_uang;
                konversi_yen(jumlah_uang, idr, usd, eur);

                system("clear");
                cout << "==================================\n";
                cout << "Rupiah(idr): \n" << idr << endl;
                cout << "Dollar(usd): \n" << usd << endl;
                cout << "Euro(eur): \n" << eur << endl;
                cout << "==================================\n";
                break;
            
            case 5: 
                system("clear");
                cout << "==================================\n";
                cout << "Anda Keluar, Program Selesai.\n";
                cout << "==================================\n";
                break;

            default:
            system("clear");
            cout << "==================================\n";
            cout << "Pilihan Anda Salah. Pilih Menu Yang Sesuai.\n";   
            cout << "==================================\n";
        }
    } while(pilihan != 5);
    return 0;
}