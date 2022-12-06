#include <iostream>
#include <algorithm>
#include "bst.hpp"


bool BST::add(int value)
{
	if (_root == nullptr)
	{
		_root = new Node(value);
		return true;
	}
	Node* tmp = _root;
	bool added = false;
	do {
		if (value == tmp->getValue())
		{
			return false;
		}

		if (value < tmp->getValue())
		{
			if (tmp->hasLeft())
			{
				tmp = tmp->getLeft();
			}
			else
			{
				tmp->setLeft(new Node(value));
				added = true;
			}
		}

		else
		{
			if (tmp->hasRight())
			{
				tmp = tmp->getRight();
			}

			else
			{
				tmp->setRight(new Node(value));
				added = true;
			}
		}
	} while (!added);
	return true;
}

bool BST::contains(int target)
{
	if (_root == nullptr)
		return false;
	Node* tmp = _root;
	do {
		if (target == tmp->getValue())
			return true;
		if (target < tmp->getValue())
			tmp = tmp->getLeft();
		else
			tmp = tmp->getRight();
	} while (tmp != nullptr);
	return false;
}

bool BST::remove(int value)
{
	if (_root == nullptr)
		return false;
	if (_root->getValue() == value)
	{
		deleteRoot(value);
		return true;
	}
	if (!_root->hasChildren())
		return false;

	Node* parent = _root;
	Node* child = (value < parent->getValue()) ? parent->getLeft() : parent->getRight();

	while (child != nullptr) {
		if (value < child->getValue())
		{
			parent = child;
			child = child->getLeft();
		}
		else if (value > child->getValue())
		{
			parent = child;
			child = child->getRight();
		}
		else {
			deleteNode(parent, child, value);
			return true;
		}
	}
	return false;
}

void BST::deleteRoot(int value)
{
	if (value != _root->getValue())
		return;
	if (!_root->hasChildren())
	{
		Node* tmp = _root;
		_root = nullptr;
		delete tmp;
	}
	else if (_root->hasRight())
	{
		int min = deleteSmallest(_root, _root->getRight());
		_root->setValue(min);
	}
	else
	{
		Node* tmp = _root;
		_root = _root->getLeft();
		delete tmp;
	}
}

void BST::deleteNode(Node* parent, Node* child, int value)
{
	if (value != child->getValue())
		return;

	if (!child->hasChildren())
	{
		if (child == parent->getLeft())
		{
			parent->setLeft(nullptr);
		}
		else
		{
			parent->setRight(nullptr);
		}
		delete child;
	}
	else if (child->hasRight())
	{
		int min = deleteSmallest(child, child->getRight());
		child->setValue(min);
	}
	else
	{
		if (child == parent->getLeft())
		{
			parent->setLeft(child->getLeft());
		}
		else
		{
			parent->setRight(child->getLeft());
		}
		delete child;
	}
}

int BST::deleteSmallest(Node* parent, Node* child)
{
	if (child->hasLeft())
	{
		return deleteSmallest(child, child->getLeft());
	}
	int min = child->getValue();

	if (child == parent->getLeft()) {
		parent->setLeft(child->getRight());
	}
	else {
		parent->setRight(child->getRight());
	}
	delete child;
	return min;
}

Node* findCommonAncestor(Node* root, Node* node1, Node* node2)
{
	if (node1.getValue() < root.getValue() && node2.getValue() < root.getValue())
	{
		return findCommonAncestor(root.getLeft(), node1, node2);
	}
	else if (node1.getValue() > root.getValue() && node2.getValue() > root.getValue())
	{
		return findCommonAncestor(root.getRight(), node1, node2);
	}
	return root;
}