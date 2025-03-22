#include "Array.hpp"
#include <ctime>
#include <iostream>

#define SIZE 300

int main(int, char **) {
  Array<int> numbers(SIZE);
  int *mirror = new int[SIZE];
  srand(time(nullptr));
  for (int i = 0; i < SIZE; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }
  for (int i = 0; i < SIZE; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < SIZE; i++)
    numbers[i] = rand();
  delete[] mirror;
  return 0;
}
