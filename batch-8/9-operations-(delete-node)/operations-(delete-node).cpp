#include <iostream>

using namespace std;

class Node
{

public:
	int value;
	Node* next;

};

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

void DeleteNode(Node*& head, int value)
{

	Node* current = head, * prev = head;

	if (current == NULL)
		return;

	if (current->value == value)
	{
		head = current->next;
		delete current;
	}

	while (current->value != value && current != NULL)
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL) return;

	prev->next = current->next;
	delete current;

}

int main()
{
	Node* head = NULL;

	InsertAtEnd(head, 1);
	InsertAtEnd(head, 2);
	InsertAtEnd(head, 3);
	InsertAtEnd(head, 4);
	InsertAtEnd(head, 5);
	InsertAtEnd(head, 6);

	DeleteNode(head, 4);

	PrintList(head);

	return 0;
}