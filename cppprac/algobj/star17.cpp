#include <iostream>

using namespace std;

class star {
	int size = 0;
public:
	star(int _s): size(_s) {}
	void maketree() const {
		int n1, n2, i, j, k;

		for (i = 0; i < size - 1; ++i) {
			n1 = size - i;
			n2 = i;
			if (size >= 2) {
				for (j = 0; j < n1; ++j) {
					cout << " ";
					if (j == n1 - 1) cout << "* ";
				}
				for (k = 0; k < n2; ++k) {
					cout << " ";
					if (k == n2 - 1) cout << "* ";
				}
				cout << "\n";
				if (i == size - 1) {//마지막 행
					for (int l = 0; l < 2 * i + 1; ++l)
						cout << "*";
				}
			}
		}

		if (i == size - 1) {//마지막 행
			for (int l = 0; l < 2 * i + 1; ++l)
				cout << "*";
		}
		cout << "\n";
	}

};

int main()
{
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	star a(n);
	a.maketree();
	return 0;
}
