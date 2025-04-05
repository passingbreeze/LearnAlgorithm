#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;
	int arr[t];

	for (int i = 0; i < t; ++i)
		cin >> arr[i];

	sort(arr, arr + t);

	for (int i = 0; i < t; ++i)
		cout << arr[i] << endl;

	return 0;
}
