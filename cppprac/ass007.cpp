#include <iostream>

using namespace std;

class nMatrix {
	int** values;
	int size;
public:
	nMatrix(int n, int x) {
		int r, c;

		int values = new int*[n];
		for (int i = 0; i < n; ++i)
			values*[i] = new int**[n];

		for (r = 0; r < n; ++r) {
			for (c = 0; c < n; ++c)
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

	nMatrix operator+(const nMatrix& a, const nMatrix& b) {
		int r, c;
		nMatrix result(a.size, 0);

		if (a.size != b.size) {
			cerr << "not matching matrix size." << endl;
			return result;
		}

		for (r = 0; r < a.size; ++r) {
			for (c = 0; c < a.size; ++c) {
				result.values[r][c] = a.values[r][c] + b.values[r][c];
			}
		}

		return result;
	}

	friend ostream& operator<< (ostream& os, const nMatrix& m) {
		for (int i = 0; i < m.size; ++i) {
			for (int j = 0; j < m.size; ++j) {
				os << m.values[i][j] << " " << endl;
			}
		}

		return os;
	}

};

int main(int argc, char const *argv[])
{
	nMatrix a(3, 0), b(3, 1), c(a);

	c = a + b;

	cout << c << endl;
	return 0;
}