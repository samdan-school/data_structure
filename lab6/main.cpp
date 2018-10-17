#include "./merge_sort.h"

#define SIZE 7

int main ()
{
    int arr[SIZE] = {38, 27, 43, 3, 9, 82, 10};

    merge_sort(arr, 0, SIZE - 1);

    return 0;
}