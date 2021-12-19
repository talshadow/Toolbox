#pragma once
#include <string>

namespace InterfaceObject {

namespace Implementation {

class Test_impl {
public:
  Test_impl();
  ~Test_impl();
  void printCout();
  int getCount();
  void setCount(int newCount);

private:
  int m_count = 0;
  std::string m_name = "Test_impl";
};

} // namespace Implementation
} // namespace InterfaceObject
