#include <vector>
#include <iostream>

using namespace std;

int main()
{
	// Tutorial
	// https://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c4027/C-Tutorial-A-Beginners-Guide-to-stdvector-Part-1.htm

	// 1
	vector<int> array(10);

	array[0] = 7;

	// 2
	try
	{
		array.at(100) = 8;
	}
	catch (out_of_range o)
	{
		cout << o.what() << endl;
	}

	// 3
	vector<char> sa;

	// sa.push_back('a')
	// to add many value to sa
	// however once avaible memory is run out it copy paste and put it in other place so it slows application

	// so we can do
	// sa.reserve(int num)
	// this would reserve at leat num in sa vector, so does not move around under those number

	// snip 1
	std::vector<int> v(10);

	// snip 2
	std::vector<int> v;
	v.reserve(10);

	// those 2 are diffrecent
	// 1st is defince vector containing 10 integers and initializes them with their default value 0
	// RUN CONSTRUCTOR
	// 2nd is define empty vector, and then tells it to make room for 10 integers.
	// DO NOT run CONSTRUCTOR

	// To check how many element would fit in the current allocated storage of a vector, use capacity() member function
	// To find out how many element are curently contained by the vector, use size() memeber function
	std::vector<int> array;
	array.reserve(10);
	array.push_back(999);
	// array.capacity(); => 10
	// array.size(); => 1

	// Only, 0 is valide index for array
	// While we created at least 10 element vector
	// Still possible to set with operator[] but ...
	// However, we cannot at() other than 0, it would produce out_of_range() error

	// Correct way to enlarging the number of element is to call resize()

	return 0;
}