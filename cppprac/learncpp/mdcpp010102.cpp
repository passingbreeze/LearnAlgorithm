/*
	Effective Modern C++ item 1 : Case 2
*/

#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
void f(T* p)
{
	cout << typeid(p).name() << ' ' << p << endl;
}

int main()
{
	int x = 27;
	const int* px = &x;
	int* const pcx = &x;

	f(&x); // p's type is int*
	f(px); // px's type is const int*
	f(pcx); // <- 원래라면 int* const*임을 예상할 수 있으나
	// int*이다.
	return 0;
}