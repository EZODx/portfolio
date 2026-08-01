#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node* prev;
};

int main()
{

	Node* head = NULL;

	Node* node1 = NULL;
	Node* node2 = NULL;
	Node* node3 = NULL;

	node1 = new Node();
	node2 = new Node();
	node3 = new Node();

	node1->value = 1;
	node2->value = 2;
	node3->value = 3;

	node1->next = node2;
	node1->prev = NULL;

	node2->next = node3;
	node2->prev = node1;

	node3->next = NULL;
	node3->prev = node2;

	head = node1;

	while (head != NULL)
	{
		cout << head->value << " ";
		head = head->next;
	}

	return 0;
}