#include <iostream>

// other https://stackoverflow.com/questions/2576022/efficient-thread-safe-singleton-in-c?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

/*
 * Meyers singleton
 * lazy: yes
 * thread-safe: yes
 * min C++ ver: C++11
 */
class Singleton
{
public:
  static Singleton& instance();
  void do_work() const;
  
protected:
  explicit Singleton();

// C++11 use = deleted
private:
  Singleton(const Singleton& rhs);
  Singleton& operator=(const Singleton& rhs);
};

Singleton::Singleton()
{
}

Singleton& Singleton::instance()
{
  // C++11 or std::call_once
  static Singleton singleton;
  return singleton;
}

void Singleton::do_work() const
{
  std::cout << "singleton" << std::endl;
}

int main()
{
  std::cout << "hello" << std::endl;
  Singleton::instance().do_work();
  return 0;
}
