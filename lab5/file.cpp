#include <iostream>
#include <fstream>
#include <string.h>
// Stream class to both read and write from / to files

using namespace std;

int main()
{
    // 2 argaar file neej bolno
    // 1 dah param n filiin ner
    // 2 dah param n mode iig zaana ios::in or ios::out
    ofstream write_file;
    write_file.open("my.txt", ios::out);
    // or 
    ofstream newfile("new.txt", ios::out);
    newfile.close();

    // File neegdsensen hesgee shalgna
    if (write_file.is_open())
    {
        cout << "My file is open" << endl;

        // Text bichne
        write_file << "This is a line.\n";
        write_file << "This is another line.\n";

        // Gej neesen file haah
        write_file.close();
    }
    else
    {
        cout << "Unable to open file!" << endl;
    }

    cout << endl << "***********************";
    cout << endl << "Reading from file" << endl << endl;

    string line;

    // unshih file aa ifstream ashiglan neene
    ifstream read_file("my.txt");
    if (read_file.is_open())
    {
        // getline iig ashiglan line bureer n awna
        while ( getline(read_file, line) )
        {
            cout << line << endl;
        }
        read_file.close();
    }

    cout << endl << "***********************";
    cout << endl << "Reading from file (char by char)" << endl << endl;

    char a_char;

    // unshih file aa ifstream ashiglan neene
    ifstream read_file_by_char("my.txt");
    if (read_file_by_char.is_open())
    {
        // getline iig ashiglan line bureer n awna
        while ( read_file_by_char.get(a_char) )
        {
            cout << a_char << ",";
        }
        read_file.close();
    }

    return 0;
}
