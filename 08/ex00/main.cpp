#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
  try {
    const int size = 10;
    std::vector<int> v(size);
    for (int i = 0; i < size; i++) {
      v[i] = i;
    }
    std::vector<int>::iterator it = easyfind(v, 3);
    std::cout << "Element found: " << *it << std::endl;
    easyfind(v, -1);
  } catch (const std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
