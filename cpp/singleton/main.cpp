#include <iostream>
#include "MeyersSingleton.h"
#include "DoubleCheckedLockingSingleton.h"

int main()
{
  std::cout << "hello" << std::endl;
  MeyersSingleton::instance().do_work();
  DoubleCheckedLockingSingleton::instance()->do_work();
  return 0;
}
