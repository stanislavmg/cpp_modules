#pragma once
#include <string>
#include <iostream>

class Brain {
public:
  Brain();
  Brain(const Brain &val);
  Brain &operator=(const Brain &val);
  virtual ~Brain();
  std::string getIdea(size_t index) const;
  void setIdea(size_t index, std::string idea);
private:
    const static size_t kIdeaSize = 100;
    std::string ideas[kIdeaSize];
};