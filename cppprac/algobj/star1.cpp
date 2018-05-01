#include <iostream>

using namespace std;

class star {
	int n;
public:
	star(int _n): n(_n) {}
	void increasing() {
		int j = 0;
		for (int i = 0; i < n; ++i) {
			j = i;
			for (int k = 0; k <= j; ++k)
				cout << "*";
			cout << endl;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	star a(n);
	a.increasing();
	return 0;
}
