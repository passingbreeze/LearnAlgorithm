#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int findmax(int* a, int n)
{
	int i;
	int max = a[0];
	for (i = 0; i < n; ++i) {
		if (max < a[i]) {
			max = a[i];
			continue;
		}

		else if (max == a[i])
			return i;
	}

	return i;
}

int main()
{
	int r = 1, a = 0, b = 0, i, f;
	cin >> r;
	if (r < 1 || r > 10000)
		return -1;

	int *res = new int[r];

	for (i = 0; i < r; ++i) {
		cin >> a >> b;
		res[i] = abs(b - a);
	}
	f = findmax(res, r);
	cout << f + 1 << ' ' << res[f] << endl;
	return 0;
}