#include <iostream>

using namespace std;

class star {
	int n;
public:
	star(int _n) : n(_n) {}
	void decreasing() {
		for (int i = n; i > 0; --i) {
			for (int j = i; j > 0; --j)
				cout << "*";
			cout << endl;
		}

	}

};

int main()
{
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	star a(n);
	a.decreasing();
	return 0;
}
