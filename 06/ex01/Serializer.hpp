#pragma once
#include "Data.hpp"
#include <iostream>

class Serializer {
public:
  Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &other);
  ~Serializer();
  static uintptr_t serialize(Data *data);
  static Data *deserialize(uintptr_t raw);
};