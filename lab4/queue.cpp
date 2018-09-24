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
    a.enqueue(9);
    a.enqueue(5);

    cout << "Garajbui element: " << a.dequeue() << endl;
    cout << "Garajbui element: " << a.dequeue() << endl;

    cout << "*** Print Queue ***" << endl;
    a.print_queue();
    return 0;
}
