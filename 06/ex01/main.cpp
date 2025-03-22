#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data = {"A"};
  Data *ptr = &data;

  uintptr_t serializedPtr = Serializer::serialize(ptr);
  Data *deserializedPtr = Serializer::deserialize(serializedPtr);
  std::cout << "Original pointer: " << ptr << std::endl;
  std::cout << "Serialized pointer: " << serializedPtr << std::endl;
  std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
  if (ptr == deserializedPtr)
    std::cout << "Serialization and deserialization successful." << std::endl;
  else
    std::cout << "Serialization and deserialization failed." << std::endl;
  return 0;
}
