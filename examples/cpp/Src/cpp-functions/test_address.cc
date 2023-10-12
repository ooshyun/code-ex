#include <iostream>
#include <algorithm> // std::find
#include <vector>    // std::vector

class TestClass
{
private:
public:
  int32_t x;
  TestClass()
  {
    x = 10;
  };
  ~TestClass(){};
};

void testClassAddress(void)
{
  TestClass *t = new TestClass;
  TestClass t2;
  int64_t *addr;
  addr = (int64_t *)t;
  addr = (int64_t *)(&t2);
  std::cout << ((TestClass *)addr)->x << std::endl;
  std::vector<int> x;
  x.push_back(10);
  x.push_back(20);
  std::cout << *(x.end() - 1) << std::endl;
}