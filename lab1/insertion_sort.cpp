#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	int a[10] = {91, 2, 73, 6, 1, 6, 7, 8, 9, 3};

	for (int i = 1; i < n; i++)
	{
		int temp = a[i];

		for (int j = i - 1; j >= 0; j--)
		{
			if (temp > a[j])
			{
				a[j + 1] = a[j];
				if (j == 0)
				{
					a[j + 1] = temp;
				}
			}
			else
			{
				a[j + 1] = temp;
				break;
			}
		}

		// int j = i - 1;
		// while (j >= 0 && temp < a[j])
		// {
		// 	a[j + 1] = a[j];
		// 	j--;
		// }

		// a[j + 1] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;
}
