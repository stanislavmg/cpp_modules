#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "usage: ./ex00 input.txt" << std::endl;
    return 1;
  }
  BitcoinExchange exchange;
  try {
    exchange.evaluatePricesFromFile(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
