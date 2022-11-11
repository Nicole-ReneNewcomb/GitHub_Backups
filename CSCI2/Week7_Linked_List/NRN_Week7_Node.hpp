#pragma once
#ifndef NRN_Week7_Node_hpp

#include <iostream>

class Node
{
public:
	Node();                        // default constructor
	Node(int value);               // constructor given int argument
	void setNext(Node* next);      // updates following node
	Node* getNext();               // returns pointer to following node
	bool hasNext();                // checks that following node exists
	int getValue();                // returns value in current node
	void setValue(int newValue);   // directly changes node value instead of updating pointer

private:
	int _value;
	Node* _next;
};

#endif /* NRN_Week7_Node_hpp */