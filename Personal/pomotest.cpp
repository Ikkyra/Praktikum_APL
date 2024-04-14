// pomodoro
//// start 
//// pause
//// resume
// Break
//// start
//// pause
//// resume
// Long Break
//// start
//// pause
//// resume
// settings
//// set work time
//// set break time
//// set long break time

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace this_thread;

void pomodoro() {
    int workTime = 25;
}

int main() {
    int time = 60;
    sleep_for(1s);
    while(time >= 0) {
        cout << "\rSisa Waktu: " << time << flush;
        sleep_for(1s);    
        time--;
    } 
}