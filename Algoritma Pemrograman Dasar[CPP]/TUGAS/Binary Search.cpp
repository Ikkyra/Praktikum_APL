#include <iostream>

using namespace std;

int main(){
    int jumlah_data, input_data, ukuran_data, cari;

    //Meminta input banyaknya data yang akan diurutkan
    cout << "Masukkan jumlah data: ";
    cin >> jumlah_data;
    cout << endl;
    int aray[jumlah_data];

    //Meminta input data yang akan diurutkan sebayank jumlah data yang di inputkan di atas
    for (int data = 0; data < jumlah_data; data++){
        cout << "Masukkan data ke " << data + 1 << " : ";
        cin >> input_data;

        //Seletah di input data dimasukkan ke dalam array
        aray[data] = input_data;
    }

    //Menampilkan data sebelum diurutkan
    cout << endl;
    cout << "Data sebelum di sort" << endl;
    for (int i = 0; i < jumlah_data; i++){
        cout << aray[i] << " ";
    }
    cout << endl;

    // n adalah banyaknya data pada array - 1
    int n = sizeof(aray) / sizeof(aray[0]) - 1;

    //Data diurutkan secara ascending menggunkan metode Heap Sort
    int ulang = n;
    while (ulang >= 0){
        for (int i = ulang; i >= 0; i--){
            int mid = (i - 1) / 2;
            if (aray[mid] < aray[i]){
                swap(aray[mid], aray[i]);
            }
        }
        swap(aray[0], aray[ulang]);
        ulang --;
    }

    //Menampilkan data setelah diurutkan
    cout << endl;
    cout << "Data setelah di sort" << endl;
    for (int a = 0; a < n + 1; a++){
    cout << aray[a] << " ";
    }

    cout << endl;
    cout << endl;
    //Meminta data yang mau di search
    cout << "Masukkan data yang mau di search: ";
    cin >> cari;

    //depan adalah indeks paling depan dari array
    int depan = 0;

    //counter adalah batasan perulangan
    int counter = 1;

    for (int i = 0; i < counter; i++){
        int tengah = (depan + n) / 2;

        if (cari == aray[tengah]){
            cout << "Yang di search adalah: " << aray[tengah] << endl;
            break;

        } else if (cari == aray[n]){
            cout << "Yang di search adalah: " << aray[n] << endl;
            break;
        
        } else if (cari == aray[depan]){
            cout << "Yang di search adalah: " << aray[depan] << endl;
            break;

        } else if (cari < aray[tengah]){
            n = tengah;
            counter += 1;

        } else if (cari > aray[tengah]){
            depan = tengah;
            counter += 1;
        }
    }
}