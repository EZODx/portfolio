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

Node* Find(Node* head, int value)
{
	while (head != NULL)
	{
		if (head->value == value)
			return head;

		head = head->next;
	}

	return NULL;
}

void InsertAfter(Node* prev_node, int value)
{

	if (prev_node == NULL)
	{
		cout << "The previous node cannot be NULL.";
		return;
	}


	Node* new_node = new Node();

	new_node->value = value;
	new_node->next = prev_node->next;
	prev_node->next = new_node;

}

int main()
{
	Node* head = NULL;

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	InsertAtBeginning(head, 5);

	PrintList(head);

	Node* N1 = Find(head, 2);

	InsertAfter(N1, 100);

	cout << "\n";
	PrintList(head);
	

	return 0;
}