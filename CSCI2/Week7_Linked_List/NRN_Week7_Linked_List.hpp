#pragma once
#ifndef NRN_Week7_Linked_List_hpp

#include "NRN_Week7_Node.hpp"
#include <iostream>

class LinkedList
{
public:
	LinkedList() {}        // constructor
	~LinkedList();         // destructor

	void add(int value);          // adds value to linked list
	int get(int index);           // returns value by given index
	bool contains(int target);    // checks if given value is included in linked list
	bool remove(int value);       // removes given value from linked list
	size_t size();                // returns number of values/nodes
	void print();                 // prints out values stored in linked list
	bool swap(int value1, int value2);  // swaps two values in linked list

private:
	Node* _head = nullptr;        // single member variable: head pointer points to head node
	void deleteLast(Node* n);     // recursive function called by destructor, deletes all nodes
	Node* findNode(int value);    // finds and returns node with given value parameter
};

#endif /* NRN_Week7_Linked_List_hpp */