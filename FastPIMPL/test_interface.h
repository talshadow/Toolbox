#pragma once
#include "FastPIMPL.h"
namespace InterfaceObject {

namespace Implementation {
class Test_impl;
}

class Test_interface {
public:
  Test_interface();
  ~Test_interface();
  void printCout();
  int getCount();
  void setCount(int newCount);

private:
  FastPIMPL<Implementation::Test_impl, 40, 8> m_impl;
};
} // namespace InterfaceObject
