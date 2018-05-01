#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int a = 0, b = 0, n = 0, i = 0;
	cin >> n;

	int* values = new int[n];
	while (i < n) {
		cin >> a >> b;
		values[i] = a + b;
		i++;
	}

	for (int j = 0; j < i; ++j)
		cout << values[j] << endl;

	delete[] values;
	return 0;
}