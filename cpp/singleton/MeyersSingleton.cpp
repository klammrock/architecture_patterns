#include "MeyersSingleton.h"

#include <iostream>

MeyersSingleton::MeyersSingleton()
{
  std::cout << "MeyersSingleton ctor" << std::endl;
}

MeyersSingleton& MeyersSingleton::instance()
{
  // C++11 or std::call_once
  static MeyersSingleton singleton;
  return singleton;
}

void MeyersSingleton::do_work() const
{
  std::cout << "MeyersSingleton" << std::endl;
}
