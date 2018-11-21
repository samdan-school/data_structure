#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> List;

#define PRIME_NUMBER 67
#define NUMBER_OF_SYSTEM 9

int calc_place(string word) {
    int charNum, sum = 0, i = 1;
    for (const char &a : word) {
        charNum = a;
        sum += (a % NUMBER_OF_SYSTEM) * pow(NUMBER_OF_SYSTEM, word.length() - i);
        i++;
    }
    return abs(sum % PRIME_NUMBER);
}

void insertWord(List dict[], string word) {
    dict[calc_place(word)].push_back(word);
}

bool searchWord(List dict[], string word) {
    List list = dict[calc_place(word)];
    if (list.empty()) {
        return false;
    }

    int i = 0;

    for (const string &a : list) {
        if (a == word) {
            cout << "Dict index is " << calc_place(word) << endl;
            cout << "Index is " << i << endl;
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    List dict[PRIME_NUMBER];
    insertWord(dict, "HI");
    insertWord(dict, "Hello");
    insertWord(dict, "nani");
    insertWord(dict, "samdan");

    searchWord(dict, "samdan");

    return 0;
}