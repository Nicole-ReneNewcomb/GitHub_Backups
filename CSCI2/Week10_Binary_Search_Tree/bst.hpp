#pragma once
#ifndef bst_hpp
#define bst_hpp

#include <iostream>
#include "node.hpp"

class BST
{
public:
	BST() { }
	~BST() { };

	bool add(int value);
	bool contains(int target);
	bool remove(int value);

	Node* findCommonAncestor(Node* root, Node* node1, Node node2);

	Node* getRoot();
	size_t size();
	int height();

private:
	Node* _root = nullptr;
	void deleteRoot(int value);
	void deleteNode(Node* parent, Node* child, int value);
	int deleteSmallest(Node* parent, Node* node);
};

#endif /* bst_hpp */
