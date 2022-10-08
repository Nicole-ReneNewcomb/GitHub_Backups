#include <iostream>
#include "arraylist.hpp"

void print(const size_t size, const size_t capacity);

int main()
{
	ArrayList list;
	print(list.size(), list.capacity());

	list.add(5);
	print(list.size(), list.capacity());

	for (int i = 1; i <= 10; i++)
		list.add(10 + i);
	print(list.size(), list.capacity());

	list[2] = 99;

	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Here starts myFlexArray: " << std::endl;

	FlexArray myFlexArray;
	std::cout << std::endl;
	std::cout << "Initial size and capacity: " << std::endl;
	print(myFlexArray.size(), myFlexArray.capacity());
	
	for (int i = 1; i <= 11; i++)
		myFlexArray.add(5 + i);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Size and capacity after adding 11 values: " << std::endl;
	print(myFlexArray.size(), myFlexArray.capacity());

	for (int i = 0; i < myFlexArray.size(); i++)
	{
		std::cout << myFlexArray[i] << " ";
	}

	myFlexArray.removeAt(10);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Size and capacity after removing 1 value: " << std::endl;
	print(myFlexArray.size(), myFlexArray.capacity());

	for (int i = 0; i < myFlexArray.size(); i++)
	{
		std::cout << myFlexArray[i] << " ";
	}

	for (int i = 0; i < 6; i++)
	{
		myFlexArray.removeAt(10 - i);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Size and capacity after removing 5 values: " << std::endl;
	print(myFlexArray.size(), myFlexArray.capacity());

	for (int i = 0; i < myFlexArray.size(); i++)
	{
		std::cout << myFlexArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	myFlexArray.removeAt(4);
	myFlexArray.removeAt(3);
	myFlexArray.removeAt(2);

	
	std::cout << "Size and capacity after removing 2 values: " << std::endl;
	print(myFlexArray.size(), myFlexArray.capacity());
	for (int i = 0; i < myFlexArray.size(); i++)
	{
		std::cout << myFlexArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	myFlexArray.removeAt(1);
	print(myFlexArray.size(), myFlexArray.capacity());
	for (int i = 0; i < myFlexArray.size(); i++)
	{
		std::cout << myFlexArray[i] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	myFlexArray.removeAt(0);
	print(myFlexArray.size(), myFlexArray.capacity());
	for (int i = 0; i < myFlexArray.size(); i++)
	{
		std::cout << myFlexArray[i] << " ";
	}
}

void print(const size_t size, const size_t capacity)
{
std::cout << "size: " << size << ", capacity: " << capacity << std::endl;
}