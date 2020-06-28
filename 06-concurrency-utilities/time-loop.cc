#include <iostream>
#include <fstream>
#include <chrono>
#include <ratio>

int main() {
  auto t0 = std::chrono::high_resolution_clock::now();

  int n = 0;

  for (int i = 0; i < (1024); ++i) {
    for (int j = 0; j < (1024 * 1024); ++j) {
      ++n;
    }
  }

  auto t1 = std::chrono::high_resolution_clock::now();

  std::cout << n << "\n";

  std::chrono::duration<double, std::ratio<1>> time_taken = t1 - t0;
  std::cout << "Elapsed time: " << time_taken.count() << "\n";
}
