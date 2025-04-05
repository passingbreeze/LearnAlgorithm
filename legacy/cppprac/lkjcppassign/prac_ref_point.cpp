#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a = 1;

	int& b = a;
	int* const pb = &a;

	cout << b << endl;
	cout << *pb << endl;

	return 0;
}
