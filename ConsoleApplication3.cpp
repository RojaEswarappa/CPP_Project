#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <chrono>

const int N = 10;
std::atomic<int> cnt = ATOMIC_VAR_INIT(N);



void reader(int id) {
    
        std::atomic_fetch_add(&cnt, 1);

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    
}



int main() {
    std::thread t1(reader,10);

    t1.join();
    std::cout << std::atomic_load(&cnt);
}