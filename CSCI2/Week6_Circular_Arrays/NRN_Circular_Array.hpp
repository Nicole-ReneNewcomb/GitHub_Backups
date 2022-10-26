#pragma once
#include <deque>

// Replace [BLANK] with the correct code
template <class T>
class VIPQueue
{
public:
	void append (T value);
	void appendHighPriority(T value);
	T remove();
private:
	std::deque<T> dq;
};