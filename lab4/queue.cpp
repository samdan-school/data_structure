#include "./queue.h"
#include <iostream>
using namespace std;

int main()
{
    Queue a;
    a.init_queue();

    a.enqueue(48);
    a.enqueue(20);
    a.enqueue(59);

    a.dequeue();

    a.print_queue();
    return 0;
}
