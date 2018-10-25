#ifndef STACK_APP_CPP
#define STACK_APP_CPP

#include "./stack.cpp"
#include <vector>

void decimal_to_binary(int number)
{
	Stack s;
	while (number > 0)
	{
		if (number % 2 == 0)
			s.push(0);
		else
			s.push(1);

		number /= 2;
	}

	while (s.top() != -1)
	{
		cout << s.pop();
	}
}

vector<vector<int>> backtracking(int n)
{
	vector<vector<int>> matrix(n, vector<int>(n));

	cout << matrix[0][0] << endl;

	return matrix;
}

#endif