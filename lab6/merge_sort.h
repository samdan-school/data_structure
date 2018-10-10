#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <fstream>
using namespace std;

void merge_sort(char file_name_1[], char file_name_2[])
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

#endif
