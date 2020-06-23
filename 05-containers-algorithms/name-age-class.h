#include <string>

class NameAge {
public:
  std::string name;
  int age;

  NameAge(): name{""}, age{0} {};
  NameAge(std::string name, int age): name{name}, age{age} {};
};

std::ostream& operator<<(std::ostream& s, const NameAge& n);
std::istream& operator>>(std::istream& s, NameAge& n);
