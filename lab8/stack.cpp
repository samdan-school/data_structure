#ifndef STACK_CPP
#define STACK_CPP

#include "./stack.h"

Stack::Stack()
{
	this->head = new node();
}

Stack::~Stack()
{
	node *current = head;

	if (current->next == nullptr)
	{
		delete head;
	}
	else
	{
		node *delete_node;
		while (current->next != nullptr)
		{
			delete_node = current;
			current = current->next;

			delete delete_node;
		}
	}
}

void Stack::push(int value)
{
	if (this->head->next == nullptr)
	{
		this->head->next = new node(value);
		return;
	}

	node *new_node = new node(value);
	new_node->next = head->next;
	head->next = new_node;
}

int Stack::pop()
{
	if (this->head->next != nullptr)
	{
		node *delete_node = this->head->next;
		int return_value = delete_node->value;

		if (delete_node->next != nullptr)
		{
			this->head->next = delete_node->next;
			delete delete_node;
			return return_value;
		}
		delete delete_node;
		this->head->next = nullptr;
		return return_value;
	}
	return -1;
}

int Stack::top()
{
	if (this->head->next != nullptr)
	{
		return this->head->next->value;
	}
	return -1;
}

#endif