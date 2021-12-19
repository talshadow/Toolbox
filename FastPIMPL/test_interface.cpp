
#include "test_impl.h"

#include "iostream"
#include "test_interface.h"

namespace InterfaceObject {
Test_interface::Test_interface() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
};

Test_interface::~Test_interface() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
};

void Test_interface::printCout() { m_impl->printCout(); }

int Test_interface::getCount() { return m_impl->getCount(); }

void Test_interface::setCount(int newCount) { m_impl->setCount(newCount); }

} // namespace InterfaceObject
