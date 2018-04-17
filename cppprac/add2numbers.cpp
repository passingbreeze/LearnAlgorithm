#include <iostream>

using namespace std;

int main()
{
	int t = 1;
	cin >> t;
	if (t < 1 || t > 1000)
		return -1;

	int *a = new int[t];
	int *b = new int[t];
	int *c = new int[t];

	for (int i = 0; i < t; ++i) {
		cin >> a[i] >> b[i];

		if (a[i] < 1 || a[i] > 10000)
			return -1;

		if (b[i] < 1 || b[i] > 10000)
			return -1;
	}

	for (int i = 0; i < t; ++i) {
		c[i] = a[i] + b[i];
		cout << c[i] << endl;
	}

	delete[] a;
	delete[] b;
	delete[] c;

	return 0;
}