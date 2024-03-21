#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void jeda(int detik) {
    this_thread::sleep_for(chrono::seconds(detik));
}

int main() {
    int ayam = 0;
}