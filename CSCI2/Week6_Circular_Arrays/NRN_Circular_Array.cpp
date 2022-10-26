#include "NRN_Circular_Array.hpp"

// replace [BLANK] with the correct code
template <class T>
void append(T value)
{
	dq.push_back(value);
}
template <class T>
void appendHighPriority(T value)
{
	dq.push_front(value);
}

template <class T>
T remove()
{
	T first = dq.front();
	dq.pop_front();
	return first;
}