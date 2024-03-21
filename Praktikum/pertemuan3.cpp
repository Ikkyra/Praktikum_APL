#include <iostream>
using namespace std;

// void angka(int var) {
//     cout << "Angka Integer: " << var << endl;

// }

// void angka(float var) {
//     cout << "Angka Float: " << var << endl;
// }

// int persegipanjang(int panjang, int lebar) {
//     return panjang * lebar;
// }

// int main() {
//     int a = 2;
//     float b = 3;
//     angka(a);
//     angka(b);
//     cout << "Hasil Persegi Panjang: " << persegipanjang(4,5) << endl;
// }

// int fungsi2(int n);

// int fungsi1(int n){
//     if(n <= 5){
//         cout << n << " - ";
//         n++;
//         fungsi2(n);
//     } else{
//         return n;
// }
// }

// int fungsi2(int n){
//     if(n <= 5){
//         cout << n << " + ";
//         n++;
//         fungsi1(n);
//     } else{
//         return n;
// }
// }

// int main(){
//     cout << " Hello " << endl;
//     fungsi1(0);
//     return 0;
// }

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int num;
    cout << "angka: ";
    cin >> num;
    cout << "Faktorial dari " << num << " adalah " << faktorial(num) << endl;
    return 0;
}