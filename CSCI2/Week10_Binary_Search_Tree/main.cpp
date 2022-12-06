#include "bst.hpp"
#include "node.hpp"

#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {

	BST tree;
	tree.add(9);
	tree.add(5);
	tree.add(15);
	tree.add(11);
	tree.add(12);
	tree.add(3);
	cout << tree.contains(9) << endl;
	
	tree.remove(9);
	tree.remove(3);
	cout << tree.findCommonAncestor(Node*, 11, 12) << endl;


	
	return 0;
}