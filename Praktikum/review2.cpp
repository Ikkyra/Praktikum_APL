#include <iostream>
using namespace std;

// Rifki Abiyan
//2309106030
//A2'23

int main() {
    int arr[2][2] = {{1, 2}, {4, 5}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}