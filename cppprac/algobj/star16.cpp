#include <iostream>

using namespace std;

class star {
	int size = 0;
public:
	star(int _n): size(_n) {}
	void makestar() const {
		int n1, n2;

		for (int i = 0; i < size; ++i) {
			n1 = size - 1 - i;
			n2 = i + 1;
			for (int j = 0; j < n1; ++j) cout << " ";
			for (int k = 0; k < n2; ++k) cout << "* ";
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
