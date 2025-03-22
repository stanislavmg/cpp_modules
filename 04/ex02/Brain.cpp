#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain &val) { *this = val; }

Brain &Brain::operator=(const Brain &val) {
  std::cout << "Brain copy assignment operator called" << std::endl;
  if (this != &val) {
    for (size_t i = 0; i < kIdeaSize; i++) {
      ideas[i] = val.ideas[i];
    }
  }
  return *this;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

std::string Brain::getIdea(size_t index) const {
    if (index >= kIdeaSize) {
        std::cout << "Index out of range" << std::endl;
        return "";
    }
    return ideas[index]; 
}

void Brain::setIdea(size_t index, std::string idea) {
    if (index >= kIdeaSize) {
        std::cout << "Index out of range" << std::endl;
        return;
    }
    ideas[index] = idea;
}