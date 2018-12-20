#include <string.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
void search(string text, string pat) {
    int n = text.length();
    int m = pat.length();
    int s, j;
    for (s = 0; s <= n - m; s++) {
        for (j = 0; j < m; j++) {
            if (pat[j] != text[s + j]) break;
        }
        if (j == m) cout << "Pattern found at : " << s << endl;
    }
}
int main() {
    string a = "THIS IS A TEST TEXT";
    string b = "TEXT";
    search(a, b);
    return 0;
}