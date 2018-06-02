#include <iostream>

using namespace std;

class prac {
	int* arr;
	int n;
public:
	prac(int num) : n(num) {
		arr = new int[num];
	}
	prac(const prac& p) : arr(p.arr), n(p.n) {}
	~prac() {
		cout << "dead" << endl;
		if (arr != nullptr) {
			delete[] arr;
		}
	}
	prac& operator= (const prac& p) {
		arr = p.arr;
		n = p.n;
		return *this;
	}

	void setnum() {
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
	}
	friend ostream& operator<< (ostream& os, const prac& p) {
		for (int i = 0; i < p.n; ++i) {
			os << (p.arr)[i] << ' ';
		}
		return os;
	}

};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	prac a(n);
	a.setnum();
	cout << a << endl;
	return 0;
}
