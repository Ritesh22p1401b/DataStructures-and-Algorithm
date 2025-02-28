// A simple C++ program to check for
// even or odd
#include <iostream>
using namespace std;

// Returns true if n is even, else odd
bool isEven(int n)
{
	bool isEven = true;
	for (int i=1; i <= n; i++) 
		isEven = !isEven;
	return isEven;
}

// Driver code
int main()
{
	int n = 101;
	isEven(n) ? cout << "Even" : cout << "Odd";
	return 0;
}
