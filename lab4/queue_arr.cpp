#include "./queue.h"
#include <iostream>
using namespace std;

int main()
{
    int queue_array[10];
    int head = 0;
    int tail = 0;
    int length = arr_len(queue_array);


    arr_enqueue(queue_array, length, head, tail, 15);
    arr_enqueue(queue_array, length, head, tail, 88);
    arr_enqueue(queue_array, length, head, tail, 17);
    arr_enqueue(queue_array, length, head, tail, 1);
    arr_enqueue(queue_array, length, head, tail, 23);
    arr_enqueue(queue_array, length, head, tail, 3);
    arr_enqueue(queue_array, length, head, tail, 9);
    arr_enqueue(queue_array, length, head, tail, 65);
    arr_enqueue(queue_array, length, head, tail, 0);
    arr_enqueue(queue_array, length, head, tail, 0);
    arr_dequeue(length, head, tail);
    arr_dequeue(length, head, tail);
    arr_dequeue(length, head, tail);
    arr_dequeue(length, head, tail);
    arr_enqueue(queue_array, length, head, tail, 0);

    cout << "Head: " << head << endl;
    cout << "Tail: " << tail << endl;

    print_arr_queue(queue_array, length, head, tail);
}
