#include <iostream>
using namespace std;

void arr_insert_value(int *arr, int &lenght, int value, int n)
{
	if (n >= lenght)
	{
		n = lenght;
		arr[n] = value;
		lenght++;
		return;
	}

	for (int i = lenght - 1; i >= n; i--)
	{
		arr[i + 1] = arr[i];
	}

	arr[n] = value;
	lenght++;
}

void arr_delete_with_position(int *arr, int &lenght, int n)
{
	if (n >= lenght)
	{
		lenght--;
		return;
	}

	for (int i = n; i < lenght - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	lenght--;
	return;
}

void arr_delete_with_value(int *arr, int &lenght, int value)
{
	int index_arr[lenght];
	int count = 0;

	for (int i = 0; i < lenght; i++)
	{
		if (arr[i] == value)
		{
			index_arr[count] = i;
			count++;
		}
	}

	for (int i = count - 1; i >= 0; i--)
	{
		arr_delete_with_position(arr, lenght, index_arr[i]);
	}
}

int main()
{
	// Init array linked list
	int link_arr[100];
	int lenght = 0;

	// Operations
	arr_insert_value(link_arr, lenght, 5, 0);
	arr_insert_value(link_arr, lenght, 9, 1);
	arr_insert_value(link_arr, lenght, 2, 2);
	arr_insert_value(link_arr, lenght, 5, 3);
	arr_insert_value(link_arr, lenght, 9, 4);
	arr_insert_value(link_arr, lenght, 1, 5);

	arr_delete_with_value(link_arr, lenght, 9);

	for (int i = 0; i < lenght; i++)
	{
		cout << i << ": " << link_arr[i] << endl;
	}
}
