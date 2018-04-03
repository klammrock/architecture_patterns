#ifndef MEYERS_SINGLETON_H
#define MEYERS_SINGLETON_H

/*
 * Meyers singleton
 * lazy: yes
 * thread-safe: yes
 * min C++ ver: C++11
 */
class MeyersSingleton
{
public:
	static MeyersSingleton& instance();
	void do_work() const;

protected:
	explicit MeyersSingleton();

// C++11 use = deleted
private:
	MeyersSingleton(const MeyersSingleton& rhs);
	MeyersSingleton& operator=(const MeyersSingleton& rhs);
};

#endif // MEYERS_SINGLETON_H

