#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <fstream>
using namespace std;

void merge_sort(const char *file_name_1, const char *file_name_2)
{
    bool condition = true;
    
    ifstream file_1(file_name_1);
    ifstream file_2(file_name_2);
    
    ofstream output("output.txt");

    if ( !file_1.is_open() || !file_2.is_open() )
    {
        cout << "File does not found!" << endl;
        return;
    }

    char one, two;
    bool getOne = true, getTwo = true;
    bool oneEnd = false;
    bool twoEnd = false;
    
    while ( condition == true )
    {
        if ( getOne )
        {
            file_1.get(one);
        }
        
        if ( getTwo )
        {
            file_2.get(two);
        }
        
        if (one > two)
        {
            output << two << " ";
            getOne = false;
            getTwo = true;
        } 
        else
        {
            output << one << " ";
            getTwo = false;
            getOne = true;
        }
        
        if ( file_1.peek() == EOF )
        {
            condition = false;
            oneEnd = true;
            
            if ( file_2.peek() != EOF )
                output << two << " ";
        }
        
        if ( file_2.peek() == EOF )
        {
            condition = false;
            twoEnd = true;
            
            if ( file_1.peek() != EOF )
                output << one << " ";
        }
    }
    
    if ( !oneEnd )
    {
        while ( file_1.get(one) )
        {
            output << one << " ";
        }
    }
    
    if ( !twoEnd )
    {
        while ( file_2.get(two) )
        {
            output << two << " ";
        }
    }
    
    file_1.close();
    file_2.close();
    output.close();
}

#endif
