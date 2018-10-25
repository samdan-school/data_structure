#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class node
{
  public:
	int value;
	node *next;

  public:
	node()
	{
		this->value = 0;
		this->next = nullptr;
	}

	node(int new_value)
	{
		value = new_value;
		this->next = nullptr;
	}
};

class Stack
{
  public:
	node *head;

  public:
	Stack();
	~Stack();
	void push(int value);
	int pop();
	int top();
};

#endif