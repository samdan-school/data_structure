#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <fstream>
using namespace std;

void merge_sort_file(char file_name_1[], char file_name_2[])
{
    ifstream file_1(file_name_1);
    ifstream file_2(file_name_2);

    if ( !file_1.is_open() || !file_2.is_open() )
    {
        cout << "File does not found!" << endl;
        exit(0);
    }

    int one, two;   
}

// Huer husnegtiig niiluulne
// arr[start, m]
// arr[m + 1, end]
// 
void merge(int *array, int start, int middle, int end)
{
    for (int index = start; index < middle; index++)
    {
        
    }   
}

// Hunegtiig 2 huvaana
// hengeniit hemjee n 1 bolon tuuneeh ih ued
void merge_sort(int *array, int start, int end)
{
    if ( start < end )
    {
        int middle_point = ( start + end ) / 2;

        merge_sort(array, start, middle_point);
        merge_sort(array, middle_point + 1, end);

        merge(array, start, middle_point, end);
    }    
}



#endif
