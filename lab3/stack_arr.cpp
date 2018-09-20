#include "./stack.h"

int main()
{
    int stack_array[100];
    int length = 0;

    arr_push(stack_array, length, 15);
    arr_push(stack_array, length, 2);
    arr_push(stack_array, length, 188);
    arr_push(stack_array, length, 89);

    arr_print_top(stack_array, length);

    arr_pop(length);
    arr_pop(length);
    arr_pop(length);
    arr_pop(length);
    arr_pop(length);

    for (int i = 0; i < length; i++)
    {
        cout << "i => " << stack_array[i] << endl;
    }

    return 0;
}
