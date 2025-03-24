#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>

std::time_t BitcoinExchange::parseDate(const std::string &dateStr) const {
  static const int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                                    31, 31, 30, 31, 30, 31};

  // check format YYYY-MM-DD
  if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
    throw std::runtime_error("Invalid date format: " + dateStr);

  int year, month, day;
  if (sscanf(dateStr.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
    throw std::runtime_error("Failed to parse date: " + dateStr);

  if (year < 1900 || month < 1 || month > 12 || day < 1)
    throw std::runtime_error("Invalid date: " + dateStr);

  // check leap year
  bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  int maxDays = (month == 2 && isLeap) ? 29 : daysInMonth[month - 1];

  if (day > maxDays)
    throw std::runtime_error("Invalid date: " + dateStr);

  std::tm tm = {};
  tm.tm_year = year - 1900;
  tm.tm_mon = month - 1;
  tm.tm_mday = day;
  std::time_t t = std::mktime(&tm);
  if (t == -1)
    throw std::runtime_error("Invalid date: " + dateStr);

  return t;
}

BitcoinExchange::BitcoinExchange() {
  static const std::string db_name = "data.csv";

  std::ifstream file(db_name);
  if (!file.is_open())
    throw std::runtime_error("Cannot open file: " + db_name);
  std::string output;
  std::getline(file, output);

  while (std::getline(file, output)) {
    std::istringstream ss(output);
    std::string date, price;
    std::getline(ss, date, ',');
    std::getline(ss, price, ',');
    try {
      exchange_[parseDate(date)] = std::atof(price.c_str());
    } catch (const std::exception &e) {
      std::cerr << "Bad input: " << e.what() << std::endl;
    }
  }
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  exchange_ = other.exchange_;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  exchange_ = other.exchange_;
  return *this;
}

void BitcoinExchange::evaluatePricesFromFile(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open())
    throw std::runtime_error("Cannot open file: " + filename);
  std::string output;
  std::getline(file, output);
  std::cout << "date | value" << std::endl;
  while (std::getline(file, output)) {
    std::istringstream ss(output);
    std::string date, price;
    std::getline(ss, date, ',');
    std::getline(ss, price, ',');
    try {
      std::time_t time = parseDate(date);
      double converted_price = std::atof(price.c_str());
      if (converted_price < 0 || converted_price > 1000)
        throw std::runtime_error("Price out of range: " + price);
      while (!exchange_.count(time))
        time -= 86400;
      std::cout << date << " | " << converted_price * exchange_[time]
                << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Bad input: " << e.what() << std::endl;
    }
  }
}
