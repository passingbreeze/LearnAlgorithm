#include <iostream>

using namespace std;

class nMatrix {
	int** values;
	int size;
public:
	nMatrix(int n, int x) {
		int r, c;
		size = n;

		values = new int*[size];
		for (int i = 0; i < size; ++i)
			values[i] = new int[size];

		for (r = 0; r < size; ++r) {
			for (c = 0; c < size; ++c)
				values[r][c] = x;
		}

	}

	~nMatrix() {
		if (values != NULL)
			delete[] values;
	}

	nMatrix(const nMatrix& m) {
		values = m.values;
		size = m.size;
	}

	nMatrix& operator+(const nMatrix& m) {
		int r, c;

		for (r = 0; r < (*this).size; ++r) {
			for (c = 0; c < (*this).size; ++c) {
				(*this).values[r][c] += m.values[r][c];
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
	cout << b ;

	c = a + b;
	//c = a.operator+(b)

	cout << c ;
	return 0;
}
