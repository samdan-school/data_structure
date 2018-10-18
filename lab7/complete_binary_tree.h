#ifndef COMPLETE_BINARY_TREE_H
#define COMPLETE_BINARY_TREE_H

#include <iostream>
using namespace std;

void root(int *array, int length);
void leaf(int *array, int start, int length);
int level(int *array, int length);
int height(int *array, int length);
void ancestor(int *array, int position, int length);
void descendant(int *array, int position, int length);
void siblings(int *array, int position, int length);
void parent(int *array, int position, int length);
void children(int *array, int position, int length);

void root(int *array, int length)
{
	cout << array[0];
}

void leaf(int *array, int start, int length)
{
	if (2 * start < length)
	{
		leaf(array, 2 * start + 1, length);
		leaf(array, 2 * start + 2, length);
	}
	else
	{
		if (start <= length)
			cout << array[start] << ", ";
	}
}

int level(int *array, int length)
{
	int count = 0;
	while (length > 1)
	{
		length /= 2;
		count++;
	}
	return count;
}

int height(int *array, int length)
{
	return level(array, length) + 1;
}

void ancestor(int *array, int position, int length)
{
	if ((position - 1) / 2 > 0)
	{
		cout << array[(position - 1) / 2] << ", ";
		ancestor(array, (position - 1) / 2, length);
	}
	else
	{
		if (position == 0)
			return;
		cout << array[0] << ", ";
		return;
	}
}

void descendant(int *array, int position, int length)
{
	if (position * 2 <= length)
	{
		if (position * 2 + 1 <= length)
			cout << array[position * 2 + 1] << ", ";
		if (position * 2 + 2 <= length)
			cout << array[position * 2 + 2] << ", ";

		descendant(array, position * 2 + 1, length);
		descendant(array, position * 2 + 2, length);
	}
}

void siblings(int *array, int position, int length)
{
	if (position == 0)
		return;

	int parent_position = (position - 1) / 2;

	if (parent_position * 2 + 1 <= length)
		cout << array[parent_position * 2 + 1] << ", ";
	if (parent_position * 2 + 2 <= length)
		cout << array[parent_position * 2 + 2] << ", ";
}

void parent(int *array, int position, int length)
{
	if (position == 0)
		return;

	cout << array[(position - 1) / 2] << ", ";
}

void children(int *array, int position, int length)
{
	if (position * 2 + 1 <= length)
		cout << array[position * 2 + 1] << ", ";
	if (position * 2 + 2 <= length)
		cout << array[position * 2 + 2] << ", ";
}

#endif