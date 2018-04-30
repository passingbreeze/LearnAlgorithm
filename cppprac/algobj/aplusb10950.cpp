#include <iostream>

using namespace std;

class aplusb {
	int m = 0;
public:
	aplusb(int _m): m(_m) {}
	aplusb& operator+(const aplusb b) {
		m += b.m;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const aplusb& c) {
		os << c.m ;
		return os;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	int a, b, n = 0;
	cin >> n;
	aplusb* values = new aplusb[n];
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;

	}
	aplusb p(a);
	cin >> b;
	aplusb q(b);
	cout << p + q << endl;
	return 0;
}