#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    int time = 60;
    std::this_thread::sleep_for(1s);
    while(time >= 0) {
        cout << "\rSisa Waktu: " << time << flush;
        std::this_thread::sleep_for(1s);    
        time--;
    } 
}