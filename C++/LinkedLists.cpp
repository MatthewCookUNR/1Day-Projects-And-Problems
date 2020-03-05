// LinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node* next;
};

Node* makeList(int size);
void printList(Node* head);
void insertNode(Node* head, int insertIndex, int value);
Node* reverseList(Node* head);
void findMiddle(Node* head);

int main()
{
	Node* head = makeList(4);
	insertNode(head, 8, 5);
	printList(head);
	head = reverseList(head);
	printList(head);
	findMiddle(head);
}

//Makes a list of given size with default values (0, 1, 2, 3....n-1)
Node* makeList(int size)
{
	if (size > 0)
	{
		Node* head = new Node();
		Node* temp = head;
		head->data = 0;
		for (int i = 1; i < size; i++)
		{
			temp->next = new Node();
			temp = temp->next;
			temp->data = i;
		}
		return head;
	}
	else
	{
		return NULL;
	}

	return NULL;
}

//Prints list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

//Inserts node at given point in list
void insertNode(Node * head, int insertIndex, int value)
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else 
	{
		int index = 0;

		//Find spot for insertion
		while (index < insertIndex - 1)
		{
			//Case given insert index is past length of list
			if (head->next == NULL)
			{
				Node* temp = new Node();
				temp->data = value;
				temp->next = head->next;
				head->next = temp;
				return;
			}
			else
			{
				head = head->next;
				index++;
			}
		}
		//Insert spot is at the end so not need to rearrange/reconnect
		if (head -> next == NULL)
		{
			Node* temp = new Node();
			temp->data = value;
			head->next = temp;
		}
		else
		{
			Node* temp = new Node();
			temp->data = value;
			temp->next = head->next;
			head->next = temp;
		}
	}
}

//Reverses list and returns head
Node * reverseList(Node* head)
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return NULL;
	}
	else
	{
		Node* prev = NULL;
		Node* current = head;
		Node* next = head;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
		return prev;
	}
}

//Finds middle value in one pass
void findMiddle(Node* head)
{
	Node* slowPtr = head;
	Node* fastPtr = head;
	if (head != NULL)
	{
		while (fastPtr != NULL && fastPtr->next != NULL)
		{
			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;
		}
		cout << slowPtr->data << endl;
	}
}