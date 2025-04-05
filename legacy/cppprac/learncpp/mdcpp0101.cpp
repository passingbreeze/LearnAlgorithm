/*
	Effective Modern C++ item 1 : Case 1
*/

#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
void f(T& p)
{
	cout << typeid(p).name() << ' ' << p << endl;
}

int main()
{
	int x = 27;
	const int cx = x;
	const int& rx = x;

	f(x); // p's type is int&
	f(cx); // p's type is const int&
	f(rx); // p's type is const int&
	// <- 원래라면 const int&&임을 예상할 수 있으나 const int&가 된다.
	return 0;
}
