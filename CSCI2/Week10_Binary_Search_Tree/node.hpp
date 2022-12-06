#pragma once
#ifndef node_hpp

#include <iostream>

class Node
{
public:
	Node(int value);
	~Node() {}

	int getValue();
	void setValue(int val);

	Node* getLeft();
	Node* getRight();
	void setLeft(Node* node);
	void setRight(Node* node);

	bool hasLeft();
	bool hasRight();
	bool hasChildren();

	size_t size();
	int height();

private:
	int _value;
	Node* _left = nullptr;
	Node* _right = nullptr;
};

#endif /* bst_hpp */