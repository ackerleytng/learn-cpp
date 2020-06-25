#include <functional>
#include <iostream>
#include <optional>
#include <vector>
#include <algorithm>

template <typename T>
void print_vector(std::vector<T>& v) {
  for (auto i: v) {
    std::cout << i << " ";
  }

  std::cout << "\n";
}

int main() {
  // Question 7
  std::vector v_int = {5, 9, -1, 200, 0};

  v_int.push_back(50);

  std::sort(v_int.begin(), v_int.end());
  print_vector(v_int);

  std::sort(v_int.begin(), v_int.end(), std::greater());
  print_vector(v_int);

  // Question 8
  std::vector v_str = {"Kant", "Plato", "Aristotle", "Kierkegard", "Hume"};

  std::sort(v_str.begin(), v_str.end(),
            [](std::string a, std::string b) { return a.compare(b) < 0; });
  print_vector(v_str);
}
