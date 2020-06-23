#include "name-age-class.h"

#include <iostream>

std::ostream& operator<<(std::ostream& s, const NameAge& n) {
  return s << "NameAge(" << n.name << ", " << n.age << ")";
}

std::istream& operator>>(std::istream& s, NameAge& n) {
  return s >> n.name >> n.age;
}
