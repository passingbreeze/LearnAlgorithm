#include <iostream>

using namespace std;

class star {
	int n = 0;
public:
	star(int _n): n(_n) {}
	void decreasing() {
		for (int i = 0; i < n; ++i) {

		}
	}

};

int main()
{
	int n;
	cin >> n;
	star a(n);
	a.decreasing();
	return 0;
}
