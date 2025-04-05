<<<<<<< HEAD
#include <iostream>
#include <cstdio>
using namespace std;
=======
#include <cstdio>
>>>>>>> c79afd2bb4adbfb2df04df9191c931ea39b6b6f8

class star {
	int size = 0;
public:
	star(int _s): size(_s) {}
	void maketree() const {
		int n1, n2, i;

<<<<<<< HEAD
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
=======
		for (i = 0; i < size - 1; ++i) {
			n1 = size - 1 - i;
			n2 = 2 * i - 1;

			if (size > 1) {
				for (int j = 0; j < n1; ++j) {
					printf(" ");
					if (j == n1 - 1) printf("* ");
				}

				for (int l = 0; l < n2; ++l) {
					if (l < n2 - 1) printf(" ");
					else printf("* ");
				}
				printf("\n");
			}
		}

		if (i == size - 1) {
			for (int l = 0; l < 2 * i + 1; ++l)
				printf("*");
			printf("\n");
		}
>>>>>>> c79afd2bb4adbfb2df04df9191c931ea39b6b6f8

	}

};

int main()
{
	int n = 0;
	scanf("%d", &n);
<<<<<<< HEAD
	if (n < 1 || n > 100) return -1;
=======
>>>>>>> c79afd2bb4adbfb2df04df9191c931ea39b6b6f8
	star a(n);
	a.maketree();
	return 0;
}
