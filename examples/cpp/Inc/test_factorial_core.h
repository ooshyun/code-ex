#ifndef TEST_FACTORIAL_CORE_H
#define TEST_FACTORIAL_CORE_H

#include <memory>
#include <iostream>
#include "../Inc/design_pattern.h"

namespace factorial{
class Core{
 friend Test;
 public:
    static Core& GetInstance() {
        static Core instance;
        return instance;
    }
    ~Core();
    int Init();
 private:
    Core() = default;
    Core(const Core&) = delete;

    std::unique_ptr<bool> _hidden = nullptr;
};

int Core::Init() {
  _hidden = std::make_unique<bool>(true);
    std::cout << "Core::Init()" << std::endl;
    std::cout << "Core::Init() _hidden: " << *_hidden << std::endl;
  return 0;
}

Core::~Core() {
  if (_hidden)_hidden.reset();
}

}

#endif  // TEST_FACTORIAL_CORE_H
