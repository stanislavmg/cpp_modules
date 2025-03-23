#include "MutantStack.hpp"
#include <iostream>

int main() {

  {
    MutantStack<int> mstack;
    mstack.push(77);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(69);
    mstack.push(3);
    mstack.push(777);
    mstack.push(7);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end() - 1;
    std::cout << "begin " << *it << std::endl;
    std::cout << "end " << *ite
              << std::endl; // this will print the last element in the stack
    std::cout << "-------------------|Test if ++ work with "
                 "iterator|--------------------\n";
    ++it;
    std::cout << "begin " << *it << std::endl;
    std::cout << "end " << *ite << std::endl;
    std::cout << "-------------------|Test if -- work with "
                 "iterator|--------------------\n";
    --it;
    std::cout << "begin " << *it << std::endl;
    std::cout << "end " << *ite << std::endl;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::cout << mstack.size() << std::endl;
    std::stack<int> s(mstack);
  }
  {
    MutantStack<std::string> mstack;
    mstack.push("Bari");
    mstack.push("Mehdi");
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push("Mehdi");
    mstack.push("77");
    mstack.push("Intra");
    mstack.push("CPP-Moudle-08");
    MutantStack<std::string>::iterator it = mstack.begin();
    MutantStack<std::string>::iterator ite = mstack.end() - 1;
    std::cout << "begin " << *it << std::endl;
    std::cout << "end " << *ite << std::endl;
    ++it;
    std::cout << "begin " << *it << std::endl;
    std::cout << "end " << *ite << std::endl;
    --it;
    std::cout << "begin " << *it << std::endl;
    std::cout << "end " << *ite << std::endl;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::cout << mstack.size() << std::endl;
    std::stack<std::string> s(mstack);
  }
  return 0;
}
