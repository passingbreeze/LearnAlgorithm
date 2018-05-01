#include <iostream>

using namespace std;

class nMatrix {
	int** values;
	int size;
public:
	nMatrix(int n, int x) {
		size = n;

		values = new int*[size];
		for (int i = 0; i < size; ++i)
			values[i] = new int[size];

		for (int r = 0; r < size; ++r) {
			for (int c = 0; c < size; ++c)
				values[r][c] = x;
		}

	}

	~nMatrix() {
		// if (values != NULL)
		delete values;
	}

	nMatrix(const nMatrix& m) {
		size = m.size;
		values = new int*[size];
		for (int i = 0; i < size; ++i)
			values[i] = new int[size];

		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				values[i][j] = m.values[i][j];
			}
		}

		// shallow copy == 주소값만 복사
		// deep copy == 새로 공간을 하나 만들어서 통째로 복사
	}

	nMatrix& operator+(const nMatrix& m) {
		int i, j;

		for (i = 0; i < size; ++i) {
			for (j = 0; j < size; ++j) {
				values[i][j] += m.values[i][j];
			}
		}

		return *this;
	}

	friend ostream& operator<< (ostream& os, const nMatrix& m) {
		for (int i = 0; i < m.size; ++i) {
			for (int j = 0; j < m.size; ++j)
				os << m.values[i][j] << " ";
			os << endl;
		}
		return os;
	}

};

int main(int argc, char const *argv[])
{
	nMatrix a(3, 1), b(3, 1), c(a);

	cout << a ;
	cout << endl;

	cout << b ;
	cout << endl;

	cout << c ;
	cout << endl;

	c = a + b;
	// cout << a + b;
	//c = a.operator+(b)

	cout << c ;
	cout << endl;
	return 0;
}
