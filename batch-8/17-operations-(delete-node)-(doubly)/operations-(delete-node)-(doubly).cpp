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

void PrintNodeDetails(Node* head)
{

	if (head->prev != NULL)
		cout << head->prev->value;
	else
		cout << "NULL";

	cout << " <--> " << head->value << " <--> ";

	if (head->next != NULL)
		cout << head->next->value << "\n";
	else
		cout << "NULL";

}

// Print details of each node in the linked list
void PrintListDetails(Node* head)

{
	cout << "\n\n";
	while (head != NULL)
	{
		PrintNodeDetails(head);
		head = head->next;
	}
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

void DeleteNode(Node*& head, Node*& nodeToDelete)
{

	if (head == NULL || nodeToDelete == NULL)
		return;

	if (head == nodeToDelete)
	{
		head = nodeToDelete->next;

		if (head != NULL)
		{
			head->prev = NULL;
		}
	}

	if (nodeToDelete->next != NULL)
	{
		nodeToDelete->next->prev = nodeToDelete->prev;
	}

	if (nodeToDelete->prev != NULL)
	{
		nodeToDelete->prev->next = nodeToDelete->next;
	}

	delete nodeToDelete;
	nodeToDelete = NULL;

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
	PrintListDetails(head);

	Node* N1 = Find(head, 500);

	DeleteNode(head, N1);

	cout << "\n\n\nLinked List Content After Deleting a Node:\n";
	PrintList(head);
	PrintListDetails(head);

	return 0;
}