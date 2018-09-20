#include <iostream>
using namespace std;

int a;

int factorial_recursive(int n);

int main()
{
    int n;
    cin >> n;
    cout << n << "-iin factorial: " << factorial_recursive(n) << endl;

    return 0;
}

int factorial_recursive(int n)
{
    if (n == 1)
        return n;
    else
        return n * factorial_recursive(n - 1);
    // Asuuh
    // a = n * factorial_recuresize(n - 1);
}
