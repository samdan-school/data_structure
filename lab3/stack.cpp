// #include "./linked_list.h"
#include "./stack.h"

int main()
{
    node *head = new node;
    head->val = 0;
    head->next = NULL;

    push(head, 15);
    push(head, 18);
    push(head, 42);
    push(head, 75);

    printTop(head);
    printList(head);
}
