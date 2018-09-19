#include <iostream>;
#include <ctime>;
using namespace std;

int main()
{
	int start_s = clock();
	int n = 10;
	int a[10] = {1, 2, 73, 6, 1, 6, 7, 8, 9, 3};

	for (int i = 0; i < n - 1; i++)
	{
		int min = a[i];
		int index = i;

		for (int j = i; j < n; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				index = j;
			}
		}

		a[index] = a[i];
		a[i] = min;
	}

	cout << "Sorted array: ";

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ", ";
	}

	cout << endl;

	int stop_s = clock();

	cout << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;

	return 0;
}
