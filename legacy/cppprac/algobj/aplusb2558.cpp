#include <iostream>

using namespace std;

class aplusb {
	int n = 0;
public:
	aplusb(int _n): n(_n) {}
	aplusb& operator+(const aplusb b) {
		n += b.n;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const aplusb& c) {
		os << c.n ;
		return os;
	}
};

int main()
{
	int a, b;
	cin >> a;
	aplusb p(a);
	cin >> b;
	aplusb q(b);
	cout << p + q << endl;
	return 0;
}