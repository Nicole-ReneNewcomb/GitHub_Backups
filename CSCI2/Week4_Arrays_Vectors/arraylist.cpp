#include "arraylist.hpp"

ArrayList::ArrayList() : ArrayList(10)                  // default constructor calls next function with capacity of 10
{
}

ArrayList::ArrayList(const size_t initialCapacity)      // called by default constructor with capacity of 10 as default
{
	this->_array = new int[initialCapacity]();          // dynamic memory allocation of new array with initialCapcity number of elements
	this->_size = 0;                                    // set size to 0
	this->_capacity = initialCapacity;                  // set capacity to initialCapacity
}

ArrayList::~ArrayList()                                 // destructor; this-> makes sure it is the object's variable that is modified
{
	delete[] this->_array;
}

size_t ArrayList::size()                                // returns size (number of elements in array)
{
	return _size;
}

size_t ArrayList::capacity()                            // returns capacity (total number of element spaces allocated for array)
{
	return _capacity;
}

int& ArrayList::operator[](int index)                   // overloaded bracket operator returns value of element at array index
{
	return _array[index];
}

void ArrayList::add(int value)                         // adds new value to array, includes if for when new array must be created
{
	if (_size == _capacity)                            // if array available spaces (capacity) filled with elements (size == capacity)
	{
		int* old = this->_array;                       // create new pointer that points to existing array memory location

		this->_capacity = _size * 2;                   // assign 2 * current size to the object's _capacity member variable
		this->_array = new int[_capacity]();           // assign a new array of updated _capacity (_size*2) to object's member pointer variable

		for (int i = 0; i < _size; i++)                // loop to copy values from old array to new array with double capacity
		{
			this->_array[i] = old[i];                  // copies element from old array at index to object's new array at same index
		}
		delete[] old;                                  // delete the old array and free up memory (deallocates memory)
	}
	*(_array + _size) = value;                         // "value at" (location of array + offset) assigned value passed as parameter to function
	_size++;                                           // _size is # of elements but also indicates next free space in index, gets incremented to next space
}													   // since _size = 2 would mean two elements at index 0 and 1, 2 is next available space

int ArrayList::get(const int index)                    // function returns "value at" object's (memory location + offset)
{
	return *(this->_array + index);                    // could use array syntax instead of pointer syntax
}

bool ArrayList::remove(int value)                      // removes given value from ArrayList; e.g. removes 89 if value in array
{
	for (int i = 0; i < _size; i++)                    // loops through ArrayList to look for value, e.g. 89
	{
		if (_array[i] == value)                        // if element in array has the same value as the value parameter, e.g. 89, at index
		{
			return removeAt(i);                        // removes the value by calling the removeAt function at that index (only removes first match in array)
		}
	}
	return false;
}

bool ArrayList::removeAt(const int index)              // function removes value from ArrayList and shifts all elements to the left to avoid null values
{
	if (index < 0 || index >= _size)                   // if invalid index, returns false value
	{
		return false;
	}
	for (int i = index + 1; i < _size; i++)            // 
	{
		int curr = i - 1;
		*(_array + curr) = *(_array + i);
	}
	*(_array + (--_size)) = 0;
	return true;
} 

bool FlexArray::removeAt(const int index)
{
	ArrayList::removeAt(index);

	if (_size == _capacity / 2)
	{
		int* old = this->_array;
		this->_capacity = _size;
		this->_array = new int[_capacity]();

		for (int i = 0; i < _size; i++)
		{
			this->_array[i] = old[i];
		}
		delete[] old;
	}
	return true;
}