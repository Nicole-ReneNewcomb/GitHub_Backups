//#include <iostream>
//
//int main()
//{
//
//	int number = 5; // allocates memory space for integer identified by number [5 stored]
//	void* ptr = &number; // ampersand tells it to get address of number instead of value
//	int* ptr2 = &number; // int lets you know what datatype is at address
//
//	std::cout << number << std::endl; // prints number (5)
//	std::cout << ptr << std::endl; // prints address 0x7ffeefbff508 (memory location)
//
//	//in *ptr, * is “dereference” or “go to” operator (star or asterisk)
//	*ptr2 = 7; // changes value of number to 7 even if printing number variable
//
//	std::cout << number << std::endl; // prints number with new value (7) changed by pointer assignment
//
//	++*ptr2; // increment number using the pointer - either (*ptr2)++ or ++*ptr2 - (8)
//	
//	std::cout << number << std::endl; // prints number with new value changed by pointer increment
//
//	ptr2++; // increments address instead of value due to ++ higher order of operation than *
//
//	std::cout << ptr2 << std::endl; // prints increased/incremented address
//
//	int number2 = *ptr2; // reads value of number and assigns it to number2
//	number--; // will reduce number from 7 to 6, but number2 stays 7
//	ptr = &number2; // updates ptr to number2 memory address
//	*ptr2 = 10; // changes number2 stored value to 10
//	float fraction = 3.5;
//	float* floatPtr = &fraction; // need float ptr to point to float instead of integer
//
//	std::cout << ptr2 << std::endl; // prints address 0x7ffeefbff508 (memory location)
//
//
//	return 0;
//}