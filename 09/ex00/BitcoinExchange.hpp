#pragma once
#include <map>
#include <fstream>

class BitcoinExchange {
public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  void evaluatePricesFromFile(const std::string &filename);
private:
  std::time_t parseDate(const std::string &dateStr) const;
  std::map<std::time_t, double> exchange_;
};
