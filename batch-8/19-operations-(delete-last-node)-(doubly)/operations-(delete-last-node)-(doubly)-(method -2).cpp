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

void DeleteLastNode(Node*& head)
{

	if (head == NULL)
		return;

	if (head->next == NULL)
	{
		delete head;
		head = NULL;
		return;
	}

	Node* current = head;
	while (current->next->next != NULL)
	{
		current = current->next;
	}

	Node* temp = current->next;
	current->next = NULL;
	delete temp;

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

	DeleteLastNode(head);

	cout << "\n\n\nLinked List Content After Deleting the Last Node:\n";
	PrintList(head);
	PrintListDetails(head);

	return 0;
}