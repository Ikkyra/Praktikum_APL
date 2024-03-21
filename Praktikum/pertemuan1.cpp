#include <iostream>
using namespace std;

// int main() {
//     int angka1 = 0;
//     int angka2 = 0;
//     cout<<"nomor1: ";
//     cin>>angka1;
//     cout<<"nomor2: ";
//     cin>>angka2;

//     int x = angka1 * angka2;
//     int x1 = angka1 / angka2;
//     int x2 = angka1 + angka2;
//     int x3 = angka1 - angka2;

//     cout<<x<<x1<<x2<<x3<<endl;
//     return 0;

// }


int main() {
    int angka = 1;
    while (angka < 10) {
        if (angka % 2 == 0){
            cout<<angka<<" ";
        }
        angka++;
    }
}