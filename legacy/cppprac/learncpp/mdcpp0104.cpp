/*
	Effective Modern C++ item 1 : Case 4
*/

#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
void f(T p)
{
	cout << typeid(p).name() << ' ' << p << endl;
}

int main(int argc, char const *argv[])
{
	const char name[] = "J. P. Briggs";
	const char* ptrToName = name;
	f(name);
	f(ptrToName);
	return 0;
}
