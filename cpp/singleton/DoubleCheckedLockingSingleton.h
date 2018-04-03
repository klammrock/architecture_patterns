#ifndef DOUBLE_CHECKED_LOCKING_SINGLETON_H
#define DOUBLE_CHECKED_LOCKING_SINGLETON_H

#include <atomic>
#include <mutex>

// https://stackoverflow.com/questions/2576022/efficient-thread-safe-singleton-in-c?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

/*
* Herb Sutter talks about the double-checked locking in CppCon 2014
* lazy: yes
* thread-safe: yes
* min C++ ver: C++11
*/
class DoubleCheckedLockingSingleton
{
public:
  static DoubleCheckedLockingSingleton* instance();
  void do_work() const;

protected:
  explicit DoubleCheckedLockingSingleton();

// C++11 use = deleted
private:
  DoubleCheckedLockingSingleton(const DoubleCheckedLockingSingleton& rhs);
  DoubleCheckedLockingSingleton& operator=(const DoubleCheckedLockingSingleton& rhs);

private:
  static std::atomic<DoubleCheckedLockingSingleton*> m_instance;
  static std::mutex m_mutex;
};

#endif // DOUBLE_CHECKED_LOCKING_SINGLETON_H
