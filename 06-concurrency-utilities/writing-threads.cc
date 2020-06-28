#include <iostream>
#include <chrono>
#include <thread>


void write_hello() {
  while (true) {
    std::cerr << "hello\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
}


void write_world() {
  while (true) {
    std::cerr << "world\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
}


int main() {
  std::thread t0(write_hello);
  std::thread t1(write_world);

  t0.join();
  t1.join();
}
