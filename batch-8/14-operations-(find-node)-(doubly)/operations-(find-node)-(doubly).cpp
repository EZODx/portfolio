#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node* prev;
};

void InsertAtBeginning(Node*& head, int value)
{

	Node* new_node = new Node();
	new_node->value = value;
	new_node->next = head;
	new_node->prev = NULL;

	if (head != NULL)
	{
		head->prev = new_node;
	}
	
	head = new_node;

}

// Print the linked list
void PrintList(Node* head)
{
	cout << "NULL <--> ";
	while (head != NULL)
	{
		cout << head->value << " <--> ";
		head = head->next;
	}
	cout << "NULL";

}

Node* Find(Node* head, int value)
{

	while (head != NULL)
	{
		if (head->value == value)
			return head;
		else
			head = head->next;
	}

	return NULL;
}

int main()
{

	Node* head = NULL;

	InsertAtBeginning(head, 5);
	InsertAtBeginning(head, 4);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 1);


	cout << "Linked List Content:\n";
	PrintList(head);

	Node* N1 = Find(head, 2);

	if (N1 != NULL)
		cout << "\n\nThe node found :)";
	else
		cout << "\n\nThe node wasn't found :(";

	return 0;
}