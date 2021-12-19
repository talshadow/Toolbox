#include "test_impl.h"
#include <iostream>
namespace InterfaceObject {
namespace Implementation {

Test_impl::Test_impl() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
Test_impl::~Test_impl() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

void Test_impl::printCout() {
  std::cout << "count is " << m_count << std::endl;
}

int Test_impl::getCount() { return m_count; }

void Test_impl::setCount(int newCount) { m_count = newCount; }

} // namespace Implementation
} // namespace InterfaceObject
