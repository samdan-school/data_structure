#include <iostream>
#include <cstdlib>
using namespace std;

void quick_sort(int *array, int start, int end);
int partition(int *array, int start, int end);
int swap(int *array, int first_index, int second_index);

void quick_sort(int *array, int start, int end)
{
    int sorted_index = partition(array, start, end);
    
    cout << endl << "PARTIAN!" << sorted_index << endl;
    
    if (sorted_index != -1)
    {
        quick_sort(array, start, sorted_index - 1);
        quick_sort(array, sorted_index + 1, end);
    }
}



int partition(int *array, int start, int end)
{
    int pivot = array[start];
    
    int compare_start = start;
    int compare_end = end;
    
    int postion = 1;
    int index = -1;
    
    for(int array_index = start; array_index < end; array_index++)
    {
        if (postion == 1)
        {
            if ( pivot >= array[compare_end] )
            {
                swap(array, compare_start, compare_end);
                index = compare_end;
                compare_start++;
                postion = 2;
            } else {
                compare_end--;
            }
        }
        
        else if (postion == 2)
        {
            if ( pivot <= array[compare_start] )
            {
                swap(array, compare_start, compare_end);
                index = compare_start;
                compare_end--;
                postion = 1;
            } else {
                compare_start++;
            }
        }
    }
        
    return index;
}

int swap(int *array, int first_index, int second_index)
{
    cout << endl << "Swap 1st: " << array[first_index];
    cout << "   2nd: " << array[second_index] << endl;
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

int main()
{
    int array[8] = {17, 2, 89, 12, 11, 45, 9, 30};
    
    quick_sort(array, 0, 7);
    
    for(int i = 0; i < 8; i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
    
    return 0;
}
