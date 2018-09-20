#include <iostream>
using namespace std;

struct node
{
	int val;
	node *next;
};
void printList(node *head);

int findLength(node *head);
void findByPosition(node *head, int n);
void findByValue(node *head, int val);

void insertSpecail(node *current, int val);
void insertValue(node *head, int val, int n);

void deleteWithPosition(node *head, int n);
void deleteWithValue(node *head, int val);
void deleteLinkedList(node *head);

int main()
{
	node *head = new node;
	head->val = 0;
	head->next = NULL;

	insertValue(head, 99, 1);
	insertValue(head, 6, 2);
	insertValue(head, 99, 3);
	insertValue(head, 1, 4);
	insertValue(head, 8, 5);

	deleteWithValue(head, 99);

	deleteWithValue(head, 8);
	deleteWithValue(head, 8);

	insertValue(head, 24, 1);

	deleteWithPosition(head, 2);

	printList(head);

	deleteLinkedList(head);
	return 0;
}

void printList(node *head)
{
	node *current = head;
	int n = findLength(head);

	for (int i = 0; i < n; i++)
	{
		current = current->next;
		cout << i << ": " << current->val << endl;
	}
}

int findLength(node *head)
{
	int count = 0;
	// current postion of linked list
	node *current = head;

	// Check current is last element
	while (current->next != NULL)
	{
		count++;
		// go to next element
		current = current->next;
	}

	return count;
}

void findByPosition(node *head, int n)
{
	node *current = head;
	int max = findLength(head);
	if (n > max)
	{
		cout << "n-ee buruu oruulsan baina." << endl;
		return;
	}

	for (int i = 0; i < n; i++)
		current = current->next;

	cout << n << " dah elementiin utga: " << current->val << endl;
}

void findByValue(node *head, int val)
{
	int count = 0;
	int i = 0;
	node *current = head;

	while (current->next != NULL)
	{
		current = current->next;
		if (current->val == val)
		{
			cout << val << " " << i << "-r elementd baina." << endl;
			count++;
		}
		i++;
	}

	if (count == 0)
		cout << val << " oldsongui." << endl;
}

void insertValue(node *head, int val, int n)
{
	node *current = head;
	node *temp;

	// hamgiin in element nemeh bolomjtoi index
	int max = findLength(head);

	// n n max duyu link listees urt ued hamgiin hoino nemne
	if (n > max)
		n = max;

	for (int i = 0; i < n; i++)
	{
		temp = current;
		current = current->next;
	}

	if (n == max)
	{
		insertSpecail(current, val);
		return;
	}

	// nemeh element
	node *new_node = new node;
	new_node->val = val;
	new_node->next = current;

	temp->next = new_node;
}

void insertSpecail(node *current, int val)
{
	node *n_current = current;
	// nemeh element
	node *new_node = new node;
	new_node->val = val;
	new_node->next = NULL;
	n_current->next = new_node;
}

void deleteWithPosition(node *head, int n)
{
	node *current = head;
	node *temp;

	// hamgiin in element nemeh bolomjtoi index
	int max = findLength(head);

	if (max == 0)
		return;

	// n n max duyu link listees urt ued hamgiin hoino nemne
	if (n > max)
		n = max;

	for (int i = 0; i < n; i++)
	{
		temp = current;
		current = current->next;
	}

	if (n == max)
	{
		delete current;
		temp->next = NULL;
		return;
	}

	// nemeh element
	temp->next = current->next;
	delete current;
}

void deleteWithValue(node *head, int val)
{
	int count = 0;
	// index of found value
	int i = 0;
	node *current = head;

	int a[findLength(head)];

	while (current->next != NULL)
	{
		current = current->next;
		if (current->val == val)
		{
			a[count] = i;
			count++;
		}
		i++;
	}

	for (int i = 0; i < count; i++)
	{
		// 1 davtalt ywah burt linked list iin hemjee 1 eer bagsah uchir i iig hasna
		deleteWithPosition(head, a[i] + 1 - i);
	}

	if (count == 0)
		cout << val << " oldsongui." << endl;
}

void deleteLinkedList(node *head)
{
	// current postion of linked list
	node *current = head;

	// Check current is last element
	while (current->next != NULL)
	{
		delete current;
		// go to next element
		current = current->next;
	}
}
