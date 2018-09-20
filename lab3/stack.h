#include <iostream>
#include "./linked_list.h"
using namespace std;

void push(node *head, int value)
{
    int len = findLength(head);
    insertValue(head, value, len + 1);
}

void pop(node *head)
{
    int len = findLength(head);
    if(len == 0)
    {
        cout << "utga baihgui baina!";
        return;
    }
    deleteWithPosition(head, len + 1);
}

void printTop(node *head)
{
    int len = findLength(head);
    findByPosition(head, len); 
}

void arr_push(int arr[], int &length, int value)
{
    arr[length] = value;
    length++;
}

void arr_pop(int &length)
{
    if (length == 0)
    {
        cout << "Please insert element!" << endl;
        return;
    }
    length--;
}

void arr_print_top(int arr[], int &length)
{
    if (length == 0)
    {
        cout << "No element in stack!" << endl;
        return;
    }
    cout << "Top element is: " << arr[length - 1] << endl;
}
