#include <iostream>

using namespace std;

class star {
	int n = 0;
public:
	star(int _n): n(_n) {}
	void makestar() const {
		for (int i = 0; i < n; ++i) {
			int n1 = n - 1 - i;
			int n2 = i + 1;

			for (int i = 0; i < n1; ++i)
				cout << " ";
			for (int i = 0; i < n2; ++i)
				cout << "*";
			cout << "\n";

		}

		for (int i = 0; i < n - 1; ++i) {
			int n3 = i + 1;
			int n4 = n - 1 - i;

			for (int i = 0; i < n3; ++i)
				cout << " ";
			for (int i = n4 - 1; i >= 0; --i)
				cout << "*";
			cout << "\n";

		}
	}

};

int main()
{
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	if (n < 1 || n > 100) return -1;
	star a(n);
	a.makestar();
	return 0;
}
