#include <iostream>
#include <algorithm>
#include "node.hpp"

Node::Node(int value)
{
	this->_value = value;
}

int Node::getValue() { return _value; }
void Node::setValue(int val) { _value = val; }

Node* Node::getLeft() { return _left; }
Node* Node::getRight() { return _right; }

void Node::setLeft(Node* node) { _left = node; }
void Node::setRight(Node* node) { _right = node; }

bool Node::hasLeft() { return _left != nullptr; }
bool Node::hasRight() { return _right != nullptr; }
bool Node::hasChildren()
{
	return hasLeft() || hasRight();
}

size_t Node::size()
{
	size_t leftSize = (hasLeft() ? _left->size() : 0);
	size_t rightSize = (hasRight() ? _right->size() : 0);
	return 1 + leftSize + rightSize;
}

int Node::height()
{
	int leftHeight = hasLeft() ? 1 + _left->height() : 0;
	int rightHeight = hasRight() ? 1 + _right->height() : 0;
	return std::max(leftHeight, rightHeight);
}