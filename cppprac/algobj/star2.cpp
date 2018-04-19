#include <iostream>

using namespace std;

class star {
	int n = 0;
public:
	star(int _n): n(_n) {}
	void increasing() {
		int n1 = 0, n2 = 0;
		for (int i = n - 1; i >= 0; --i) {
			n1 = i;
			n2 = n - i;
			for (int j = 0; j < n1; ++j)
				cout << " ";
			for (int k = 0; k < n2; ++k)
				cout << "*";
			cout << endl;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	if (n < 1 || n > 100) return -1;
	star a(n);
	a.increasing();
	return 0;
}
