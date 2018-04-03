#include "DoubleCheckedLockingSingleton.h"

#include <iostream>

std::atomic<DoubleCheckedLockingSingleton*> DoubleCheckedLockingSingleton::m_instance { nullptr };
std::mutex DoubleCheckedLockingSingleton::m_mutex;

DoubleCheckedLockingSingleton::DoubleCheckedLockingSingleton()
{
}

DoubleCheckedLockingSingleton* DoubleCheckedLockingSingleton::instance()
{
	if (m_instance == nullptr)
	{
		std::lock_guard<std::mutex> lock(m_mutex);

		if (m_instance == nullptr)
		{
			m_instance = new DoubleCheckedLockingSingleton();
		}
	}

	return m_instance;
}

void DoubleCheckedLockingSingleton::do_work() const
{
  std::cout << "DoubleCheckedLockingSingleton" << std::endl;
}
