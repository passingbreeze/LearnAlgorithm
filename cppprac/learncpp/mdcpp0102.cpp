/*
	Effective Modern C++ item 1 : Case 2
 */

#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
void f(T&& p)
{
	cout << typeid(p).name() << ' ' << p << endl;
}

template<typename T>
void g(T p)
{
	cout << typeid(p).name() << ' ' << p << endl;
}

int main(int argc, char const *argv[])
{
	int x = 27;
	const int cx = x;
	const int& rx = x;
	const char* const ptr = "Fun with pointers";


	f(x); // x is lvalue, T == int&, T of p == int&&이 아니라 int&
	f(cx); // cx is lvalue, T == const int&, T of p == const int&&이 아니라 const int&
	f(rx); // rx is lvalue, T == const int& (ignore case)
	f(27); // 27 is rvalue, T(rvalue) == literaltype == int
	// -> T(lvalue) of P == int&&
	g(x);
	g(cx);
	g(rx);
	g(ptr); // ptr is lavlue, T == const char*, T of P == const char*
	return 0;
}