#include <iostream>

using namespace std;

class star {
	int n;
public:
	star() : n(0) {}
	void decreasing(int k) {
		n = k;
		for (int i = n; i > 0; --i)
			cout << "*";
		cout << endl;
		decreasing(k - 1);
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	star a;
	a.decreasing(n);
	return 0;
}
