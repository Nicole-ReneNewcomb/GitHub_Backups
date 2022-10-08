#ifndef arraylist_hpp

#include <stdio.h>

class ArrayList
{
public:
	ArrayList();                           // default constructor
	ArrayList(const size_t capacity);      // constructor that includes initial capacity
	~ArrayList();                          // destructor (deletes / deallocates memory of array)

	size_t size();                         // function that gets size; size_t is very large unsigned integer type
	size_t capacity();                     // function that gets capacity
	int& operator[](int i);                // overloaded bracket operator for setting/getting element at given index
	void add(int value);                   // add function to add value
	int get(const int index);              // get function to get value by index
	bool remove(int value);                // remove function to remove particular value
	virtual bool removeAt(const int index);// removeAt function to remove function at particular index

protected:
	int* _array;                           // pointer that points to array
	size_t _size;                          // size of array (number of elements in array); size_t is very large unsigned integer type
	size_t _capacity;                      // capacity of array (total available element spaces)
};

class FlexArray : public ArrayList
{
public:
	bool removeAt(const int index);        // derived class function should override the base class version
};

#endif /* arraylist_hpp */