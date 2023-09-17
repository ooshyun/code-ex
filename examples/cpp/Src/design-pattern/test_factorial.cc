#include "../Inc/test_factorial_core.hpp"

namespace factorial {
bool Test::Main() {
    if (factorial::Core::GetInstance()._hidden)
        return *factorial::Core::GetInstance()._hidden;
    else
        return false;
};

int Init() {
    return factorial::Core::GetInstance().Init();
}
}  //namespace factorial
