#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n = 0, i;
	cin >> n;
	int* b = new int[n];
	for (i = 0; i < n; ++i)
		cin >> b[i];
	sort(b, b + n);
	cout << b[0] << ' ' << b[n - 1] << endl;
	delete[] b;
	return 0;
}

