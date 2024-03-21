#include <iostream>

using namespace std;


int main(){
    int mid, ulang, n, jumlah_data, input_data;

    //Meminta input banyaknya data yang akan diurutkan
    cout << "Masukkan jumlah data yang di sort: ";
    cin >> jumlah_data;

    int data[jumlah_data];

    //Meminta input data yang akan diurutkan sebayank jumlah data yang di inputkan di atas
    for (int i = 0; i < jumlah_data; i++){
        cout << "Masukkan data ke " << i + 1 << " : ";
        cin >> input_data;

    //Seletah di input, data dimasukkan ke dalam array
        data[i] = input_data;
    }
    cout << endl;

    //Menampilkan data sebelum diurutkan
    cout << "Data sebelum di sort" << endl;
    for (int j = 0; j < jumlah_data; j++){
        cout << data[j] << " ";
    }
    cout << endl;
    cout << endl;
    
    // n adalah banyaknya data pada array - 1
    n = sizeof(data) / sizeof(data[0]) - 1;

    //Data diurutkan secara ascending menggunkan metode Heap Sort
    ulang = n;
    while (ulang >= 0){
        for (int k = ulang; k >= 0; k--){
            mid = (k - 1) / 2;
            if (data[mid] < data[k]){
                swap(data[mid], data[k]);
            }
        }
        swap(data[0], data[ulang]);
        ulang --;
    }
    
    //Menampilkan data setelah diurutkan
    cout << "Data setelah di sort" << endl;
    for (int a = 0; a < n + 1; a++){
    cout << data[a] << " ";
    }
}