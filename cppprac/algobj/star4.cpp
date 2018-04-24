#include <iostream>

using namespace std;

class star {
	int n = 0;
public:
	star(int _n) : n(_n) {}
	void decreasing() const {
		for (int i = 0; i < n; ++i) {
			int n1 = i;
			int n2 = n - i;
			for (int j = 0; j < n1; ++j) cout << " ";
			for (int k = 0; k < n2; ++k) cout << "*";
			cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	star a(n);
	a.decreasing();
	return 0;
}