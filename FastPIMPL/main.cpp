
#include "test_interface.h"
#include <algorithm>
#include <thread>
#include <vector>

int main() {
  InterfaceObject::Test_interface obj;
  obj.printCout();
  obj.setCount(3);
  obj.printCout();
  return 0;
}
