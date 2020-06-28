#include <array>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include <regex>


std::string get_clang_path() {
  std::string out;

  std::array<char, 128> buffer;

  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen("which clang", "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed");
  }

  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    out += buffer.data();
  }

  // Trim
  out.erase(std::remove(out.begin(), out.end(), '\n'), out.end());

  return out;
}


std::vector<double> find_decimals(std::string file_name) {
  std::vector<double> out;

  std::ifstream file(file_name);
  if (!file) {
    throw std::runtime_error("Can't find " + file_name);
  }

  std::regex pat(R"((\d+\.\d+))");

  for (std::string line; getline(file, line);) {
    std::regex_token_iterator<std::string::iterator> rend;
    std::regex_token_iterator<std::string::iterator> tokens(
        line.begin(),
        line.end(),
        pat);

    while (tokens != rend) {
      out.push_back(std::stod(*tokens));
      ++tokens;
    }
  }

  return out;
}


int main(int argc, char* argv[]) {
  std::string path;

  // Get some path to work on, default to clang binary
  if (argc > 1) {
    path = argv[1];
  } else {
    path = get_clang_path();
  }

  auto decimals = find_decimals(path);

  for (auto d : decimals) {
    std::cout << d << "\n";
  }
}
