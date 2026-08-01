#include <iostream>

using namespace std;

class Node
{

public:
	int value;
	Node* next;

};

void InsertAtBeginning(Node*& head, int value)
{
	Node* new_node = new Node();

	new_node->value = value;
	new_node->next = head;

	head = new_node;

}

void PrintList(Node* head)
{

	while (head != NULL)
	{
		cout << head->value << " ";
		head = head->next;
	}

}

void InsertAtEnd(Node*& head, int value)
{
	Node* new_node = new Node();

	new_node->value = value;
	new_node->next = NULL;


	if (head == NULL)
	{
		head = new_node;
		return;
	}

	Node* last_node = head;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}

	last_node->next = new_node;

}

int main()
{
	Node* head = NULL;

	InsertAtEnd(head, 1);
	InsertAtEnd(head, 2);
	InsertAtEnd(head, 3);
	InsertAtBeginning(head, 0);

	PrintList(head);

	return 0;
}