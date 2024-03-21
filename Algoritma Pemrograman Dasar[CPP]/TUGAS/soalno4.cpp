#include <iostream>
using namespace std;

int main() {
    const char* seragam = "putih & hitam";
    const char* pointer_seragam;

    pointer_seragam = seragam;

    cout << "Seragam hari ini adalah: " << pointer_seragam << endl;

    return 0;
}
