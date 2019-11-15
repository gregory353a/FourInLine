#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>

int counter{65535};
std::mutex mtx;

void change(int delta) {
    for(auto i = 0U; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        {
            std::lock_guard<std::mutex> _(mtx);
            //mtx.lock();
            counter += delta;
            //mtx.unlock();
        }
    }
}

int main() {
    std::thread thr1(change, -1);
    std::thread thr2(change, 1);
    thr1.join();
    thr2.join();
    std::cout << "65535 = " << counter << '\n';
}
