#include "NRN_Week7_Node.hpp"

Node::Node() : Node(0)     // default constructor calls constructor with zero int value
{
}

Node::Node(int value)      // constructor initializes _value to given value
{
	this->_value = value;
	this->_next = nullptr;
}

void Node::setNext(Node* next)    // updates following node _next using given pointer parameter
{
	this->_next = next;
}

Node* Node::getNext()          // returns pointer to next node
{
	return _next;
}

bool Node::hasNext()          // checks that _next is not null (next node exists)
{
	return _next != nullptr;
}

int Node::getValue()          // returns value of node
{
	return _value;
}

void Node::setValue(int newValue)    // directly updates existing value in node
{                                    // instead of changing pointers to new node with new value
	this->_value = newValue;
}