#include "./queue.h"
#include <iostream>
using namespace std;

int main()
{
    int queue_array[100];
    int head = 0;
    int tail = 0;

    arr_enqueue(queue_array, tail, 15);
    arr_enqueue(queue_array, tail, 88);
    arr_enqueue(queue_array, tail, 17);
    arr_enqueue(queue_array, tail, 1);
    arr_enqueue(queue_array, tail, 23);

    arr_dequeue(head);

    for (int i = head; i < tail; i++)
        cout << queue_array[i] << endl;
}
