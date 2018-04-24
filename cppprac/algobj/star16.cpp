#include <iostream>

using namespace std;

class star {
	int n[100];
public:
	star(int _n) {
		for (int i = 0; i < _n; ++i)
			n[i] = i + 1;

	}
	void makestar() const {
		for (int i = 0; i < n; ++i)
			cout << "* ";
		cout << "\n";
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
