#include <iostream>

using namespace std;

#define CALL_WITH_MAX(a,b) ((a) > (b) ? (a) : (b))
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a = 0, b = 0;
	cin >> a >> b;

	cout << CALL_WITH_MAX(a, b) << endl;
	cout << CALL_WITH_MAX(++a, b) <<  endl;
	cout << a << ' ' << b << endl;
	cout << CALL_WITH_MAX(++a, 10+b) << endl;
	cout << a << ' ' << b << endl;
	return 0;
}
