#include <iostream>
#include "NRN_Week7_Linked_List.hpp"

int main(int argc, const char* argv[]) {

	LinkedList list;
	list.add(5);
	list.add(7);
	list.add(3);
	list.add(9);
	list.print();

	// list.remove(5);
	// list.remove(3);
	list.swap(5, 3);
	list.print();

	return 0;
}