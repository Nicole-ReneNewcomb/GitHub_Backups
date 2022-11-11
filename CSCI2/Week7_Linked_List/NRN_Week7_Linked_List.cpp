#include "NRN_Week7_Linked_List.hpp"

LinkedList::~LinkedList()
{
	if (_head == nullptr)        // if head is null, returns
		return;
	if (_head->hasNext())        // if hasNext node, calls deleteLast function
	{
		deleteLast(_head);
	}
	Node* tmp = _head;          // after returning from deleteLast
	_head = nullptr;            
	delete tmp;                 // deletes (5) node
}

// assume linked list: head -> (5) -> (7) -> (3) -> null
void LinkedList::deleteLast(Node* n)  // first passed pointer to (5) (_head node) by destructor
{
	if (n == nullptr || !n->hasNext())
		return;
	if (n->getNext()->hasNext())
	{
		deleteLast(n->getNext());    // function calls itself recursively on next node, (7) then (3)
	}
	Node* next = n->getNext();
	n->setNext(nullptr);          // pointer from (7) to (3) set to null, then pointer between (5) & (7)
	delete next;                  // deletes (3) from memory, then (7)
}

// assume empty linked list head -> null, then add (4), (9), (5)
void LinkedList::add(int value)   // adds new value to linked list
{
	if (_head == nullptr)         // if _head has nullptr (empty linked list)
	{
		_head = new Node(value);   // new value (say (4)) added to _head of linked List
		return;
	}
	Node* tmp = _head;             // if linked list has head value (not empty list)
	while (tmp->hasNext())
	{
		tmp = tmp->getNext();
	}
	tmp->setNext(new Node(value));   // creates new node and sets last existing node to point to it
}  // created linked list with head -> (4) -> (9) -> (5) -> null

int LinkedList::get(int index)
{
	if (_head == nullptr)
		return -1;

	Node* tmp = _head;
	for (int i = 0; i < index; i++)    // uses loop to move through index of linked list
	{
		tmp = tmp->getNext();
		if (tmp == nullptr)
		{
			return -1;
		}
	}
	return tmp->getValue();            // returns value at the index value
}

bool LinkedList::contains(int target)
{
	Node* tmp = _head;
	while (tmp != nullptr)
	{
		if (tmp->getValue() == target)   // compares node value to target value parameter
		{
			return true;
		}
		tmp = tmp->getNext();
	}
	return false;
}

bool LinkedList::remove(int value)
{
	if (_head == nullptr)
		return false;
	if (_head->getValue() == value)
	{
		Node* tmp = _head;
		_head = _head->getNext();
		delete tmp;
		return true;
	}
	Node* tmp = _head;
	while (tmp->hasNext())
	{
		Node* next = tmp->getNext();
		if (next->getValue() == value)
		{
			tmp->setNext(next->getNext());
			delete next;
			return true;
		}
		tmp = next;
	}
	return false;
}

size_t LinkedList::size()    // returns number of nodes/values
{
	if (_head == nullptr)
		return 0;
	size_t count = 1;
	Node* tmp = _head;
	while (tmp->hasNext())
	{
		tmp = tmp->getNext();
		count++;                  // increments count as nodes found in loop
	}
	return count;                // returns count/size
}

void LinkedList::print()
{
	std::cout << "head -> ";
	for (int i = 0; i < size(); i++)
	{
		std::cout << get(i) << " -> ";
	}
	std::cout << " null\n";
}

bool LinkedList::swap(int value1, int value2)
{
	Node* tmp1 = findNode(value1);
	Node* tmp2 = findNode(value2);
	if (tmp1 == nullptr || tmp2 == nullptr)
	{
		return false;
	}
	tmp1->setValue(value2);
	tmp2->setValue(value1);
	return true;
}

Node* LinkedList::findNode(int value)
{
	Node* tmp = _head;
	while (tmp != nullptr)
	{
		if (tmp->getValue() == value)
		{
			return tmp;
		}
		tmp = tmp->getNext();
	}
	return tmp;
}