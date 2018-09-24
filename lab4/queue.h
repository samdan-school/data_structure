#include <iostream>
using namespace std;

#define array_len(a) ( sizeof(a) / sizeof(a[0]) )

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
        tail = new node;
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

        node *delete_node = head->next->next;
        int return_data = delete_node->data;

        length--;
        
        head->next->next = delete_node->next;

        delete delete_node;

        return return_data;
    }

    int print_length()
    {
        return length;
    }

    void print_queue()
    {
        node *current = head->next->next;

        for (int i = 0; i < length; i++)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};


void arr_enqueue(int arr[], int &head, int &tail, int value)
{
    int tail_postion;
    if (++tail >= (int)(sizeof(arr) / sizeof(*arr)))
        tail_postion = 0;
    else
        tail_postion = tail;

    if (head == tail++)
    {
        cout << "Husnegt duursen baina!";
        return;
    }
    arr[tail] = value;
}

void arr_dequeue(int &head, int &tail)
{
    head++;
}

int check_head(int &head, int &tail)
{

}