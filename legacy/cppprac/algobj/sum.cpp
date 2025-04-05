#include <iostream>

using namespace std;

int sum(int v)
{
	if (v == 1) return v;
	return sum(v - 1) + v;
}

int main()
{
	int t = 0;
	cin >> t;

	cout << sum(t) << endl;
	return 0;
}
