#include <iostream>
using namespace std;

#define arr_len(a) (sizeof(a) / sizeof(*a))

struct node {
    int data;
    node *next;
};

class Queue
{
    // member
    public:
        node *head;
        node *tail;
        int length;

    // Functions
    void init_queue()
    {
        length = 0;
        head = new node;
        tail = head;
        head->next = tail;
    }
    void enqueue(int value)
    {
        node *new_node = new node;
        new_node->data = value;
        new_node->next = 0;

        length++;

        tail->next = new_node;
        tail = new_node;
    }

    int dequeue()
    {
        if (length == 0)
            return -2147483648;

        node *delete_node = head->next;
        int return_data = delete_node->data;

        length--;
        
        head->next = delete_node->next;

        delete delete_node;

        return return_data;
    }

    int print_length()
    {
        return length;
    }

    void print_queue()
    {
        node *current = head->next;

        for (int i = 0; i < length; i++)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};


void arr_enqueue(int arr[], int &length, int &head, int &tail, int value)
{
    if (tail == length)
    {
        if (head == 0)
        {
            cout << "Array is full!" << endl;
            return;
        }
        tail = 0;
        arr[0] = value;
        return;
    } else {
        if (tail + 1 == head)
        {
            cout << "Array is full!" << endl;
            return;
        }
        arr[tail] = value;
        tail++;

        return;
    }
}

void arr_dequeue(int &length, int &head, int &tail)
{
    if (head + 1 == length)
    {
        if (tail == length)
        {
            cout << "Array is empty!" << endl;
            return;
        }
        head = 0;
        return;
    } else {
        if(head == tail) 
        {
            cout << "Array is empty!" << endl;
            return;
        }
        head++;
    }
}

void print_arr_queue(int arr[], int length, int head, int tail)
{
    while (head != tail)
    {
        if(head < length)
        {
            cout << head << ": " <<  arr[head] << endl;
            head++;
            continue;
        } else {
            head = 0;
            cout << head << ": " <<  arr[head] << endl;
        }
    }
}
