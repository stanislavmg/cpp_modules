#include "Base.hpp"
#include <iostream>

Base *generate() {
  int random = rand() % 3;
  switch (random) {
  case 0:
    std::cout << "A instance created" << std::endl;
    return new A();
  case 1:
    std::cout << "B instance created" << std::endl;
    return new B();
  default:
    std::cout << "C instance created" << std::endl;
    return new C();
  }
  return new Base();
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;
  } catch (...) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B" << std::endl;
  } catch (...) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C" << std::endl;
  } catch (...) {
  }
}

int main() {
  Base *b;
  Base *a;
  Base *c;

  a = new A();
  c = new C();
  for (int i = 0; i < 3; i++) {
    b = generate();
    identify(*b);
    delete b;
  }
  delete a;
  delete c;
  return 0;
}
