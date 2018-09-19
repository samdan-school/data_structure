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
    deleteWithPosition(head, len + 1);
}

void printTop(node *head)
{
    int len = findLength(head);
    findByPosition(head, len); 
}
