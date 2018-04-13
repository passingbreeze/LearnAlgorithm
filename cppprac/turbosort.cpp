#include <iostream>

using namespace std;

void turbosort(int* a, int n)
{
	int temp = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j)
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	}

}

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;
	int arr[t];

	for (int i = 0; i < t; ++i)
		cin >> arr[i];

	turbosort(arr, t);

	for (int i = 0; i < t; ++i)
		cout << arr[i] << endl;

	return 0;
}
