#include <iostream>
#include <cstdio>
using namespace std;

class star {
	int size = 0;
public:
	star(int _s): size(_s) {}
	void maketree() const {
		int n1, n2, i, j, k;

		for (i = 0; i < size; ++i) {
			n1 = size - i;
			n2 = i;
			for (int j = 0; j < n1; ++j) printf(" ");
			for (int k = 0; k < n2; ++k) printf("*");


		}

		if (i == size) {
			for (int l = 0; l < 2 * i - 1; ++l)
				printf("*");
		}
		printf("\n");

	}

};

int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n < 1 || n > 100) return -1;
	star a(n);
	a.maketree();
	return 0;
}
