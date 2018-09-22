#include <iostream>;
using namespace std;

int main()
{
	int n = 10;
	int a[10] = {1, 2, 73, 6, 1, 6, 7, 8, 9, 3};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
