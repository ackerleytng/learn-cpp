#include <iostream>
#include <random>
#include <vector>

class NormalRandInt {
 public:
  NormalRandInt(double mu, double sigma) : dist {mu, sigma} {}
  int operator()() { return dist(re); }
  void seed(int s) { re.seed(s); }

 private:
  std::default_random_engine re;
  std::normal_distribution<> dist;
};


void display(const std::vector<int> &histogram) {
  int i = 0;
  for (auto count : histogram) {

    if (i < 10) {
      std::cout << " " << i << ": ";
    } else {
      std::cout << i << ": ";
    }

    for (int j = 0; j < count / 14; ++j) {
      std::cout << "*";
    }

    std::cout << "\n";

    ++i;
  }
}


int main() {
  constexpr int range_top = 30;
  NormalRandInt rand(range_top / 2, range_top / 6.3);
  std::vector<int> histogram(range_top);

  for (int i = 0; i < 10000; ++i) {
    int n = int(rand());
    if ((n >= 0) && (n <= range_top)) {
      ++histogram[n];
    }
  }

  display(histogram);
}
