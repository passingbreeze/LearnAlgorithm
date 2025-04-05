#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	char *d[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	if (x < 1 || x > 12) return -1;
	else if (y < 1 || y > 31) return -1;


	if (y % 7 == 0) {
		if (x == 1) printf("%s\n", d[0]);

		if (x == 2) {
			if (y > 28) return -1;
			printf("%s\n", d[3]);
		}

		if (x == 3) printf("%s\n", d[3]);
		if (x == 4) {
			if (y > 30) return -1;
			printf("%s\n", d[6]);
		}

		if (x == 5) printf("%s\n", d[1]);
		if (x == 6) {
			if (y > 30) return -1;
			printf("%s\n", d[4]);
		}
		if (x == 7) printf("%s\n", d[0]);
		if (x == 8) printf("%s\n", d[2]);
		if (x == 9) {
			if (y > 30) return -1;
			printf("%s\n", d[5]);
		}
		if (x == 10) printf("%s\n", d[0]);
		if (x == 11) {
			if (y > 30) return -1;
			printf("%s\n", d[3]);
		}
		if (x == 12) printf("%s\n", d[5]);
	}

	if (y % 7 == 1) {
		if (x == 1) printf("%s\n", d[1]);

		if (x == 2) {
			if (y > 28) return -1;
			printf("%s\n", d[4]);
		}

		if (x == 3) printf("%s\n", d[4]);
		if (x == 4) {
			if (y > 30) return -1;
			printf("%s\n", d[0]);
		}

		if (x == 5) printf("%s\n", d[2]);
		if (x == 6) {
			if (y > 30) return -1;
			printf("%s\n", d[5]);
		}
		if (x == 7) printf("%s\n", d[0]);
		if (x == 8) printf("%s\n", d[3]);
		if (x == 9) {
			if (y > 30) return -1;
			printf("%s\n", d[6]);
		}
		if (x == 10) printf("%s\n", d[1]);
		if (x == 11) {
			if (y > 30) return -1;
			printf("%s\n", d[4]);
		}
		if (x == 12) printf("%s\n", d[6]);
	}

	if (y % 7 == 2) {
		if (x == 1) printf("%s\n", d[2]);

		if (x == 2) {
			if (y > 28) return -1;
			printf("%s\n", d[5]);
		}

		if (x == 3) printf("%s\n", d[5]);
		if (x == 4) {
			if (y > 30) return -1;
			printf("%s\n", d[1]);
		}

		if (x == 5) printf("%s\n", d[3]);
		if (x == 6) {
			if (y > 30) return -1;
			printf("%s\n", d[6]);
		}
		if (x == 7) printf("%s\n", d[2]);
		if (x == 8) printf("%s\n", d[4]);
		if (x == 9) {
			if (y > 30) return -1;
			printf("%s\n", d[0]);
		}
		if (x == 10) printf("%s\n", d[2]);
		if (x == 11) {
			if (y > 30) return -1;
			printf("%s\n", d[5]);
		}
		if (x == 12) printf("%s\n", d[0]);
	}

	if (y % 7 == 3) {
		if (x == 1) printf("%s\n", d[3]);

		if (x == 2) {
			if (y > 28) return -1;
			printf("%s\n", d[6]);
		}

		if (x == 3) printf("%s\n", d[6]);
		if (x == 4) {
			if (y > 30) return -1;
			printf("%s\n", d[2]);
		}

		if (x == 5) printf("%s\n", d[4]);
		if (x == 6) {
			if (y > 30) return -1;
			printf("%s\n", d[0]);
		}
		if (x == 7) printf("%s\n", d[3]);
		if (x == 8) printf("%s\n", d[5]);
		if (x == 9) {
			if (y > 30) return -1;
			printf("%s\n", d[1]);
		}
		if (x == 10) printf("%s\n", d[3]);
		if (x == 11) {
			if (y > 30) return -1;
			printf("%s\n", d[6]);
		}
		if (x == 12) printf("%s\n", d[1]);
	}

	if (y % 7 == 4) {
		if (x == 1) printf("%s\n", d[4]);

		if (x == 2) {
			if (y > 28) return -1;
			printf("%s\n", d[0]);
		}

		if (x == 3) printf("%s\n", d[0]);
		if (x == 4) {
			if (y > 30) return -1;
			printf("%s\n", d[3]);
		}

		if (x == 5) printf("%s\n", d[5]);
		if (x == 6) {
			if (y > 30) return -1;
			printf("%s\n", d[1]);
		}
		if (x == 7) printf("%s\n", d[4]);
		if (x == 8) printf("%s\n", d[6]);
		if (x == 9) {
			if (y > 30) return -1;
			printf("%s\n", d[2]);
		}
		if (x == 10) printf("%s\n", d[4]);
		if (x == 11) {
			if (y > 30) return -1;
			printf("%s\n", d[0]);
		}
		if (x == 12) printf("%s\n", d[2]);
	}

	if (y % 7 == 5) {
		if (x == 1) printf("%s\n", d[5]);

		if (x == 2) {
			if (y > 28) return -1;
			printf("%s\n", d[1]);
		}

		if (x == 3) printf("%s\n", d[1]);
		if (x == 4) {
			if (y > 30) return -1;
			printf("%s\n", d[4]);
		}

		if (x == 5) printf("%s\n", d[6]);
		if (x == 6) {
			if (y > 30) return -1;
			printf("%s\n", d[2]);
		}
		if (x == 7) printf("%s\n", d[5]);
		if (x == 8) printf("%s\n", d[0]);
		if (x == 9) {
			if (y > 30) return -1;
			printf("%s\n", d[3]);
		}
		if (x == 10) printf("%s\n", d[5]);
		if (x == 11) {
			if (y > 30) return -1;
			printf("%s\n", d[1]);
		}
		if (x == 12) printf("%s\n", d[3]);
	}

	if (y % 7 == 6) {
		if (x == 1) printf("%s\n", d[6]);

		if (x == 2) {
			if (y > 28) return -1;
			printf("%s\n", d[2]);
		}

		if (x == 3) printf("%s\n", d[2]);
		if (x == 4) {
			if (y > 30) return -1;
			printf("%s\n", d[5]);
		}

		if (x == 5) printf("%s\n", d[0]);
		if (x == 6) {
			if (y > 30) return -1;
			printf("%s\n", d[3]);
		}
		if (x == 7) printf("%s\n", d[6]);
		if (x == 8) printf("%s\n", d[1]);
		if (x == 9) {
			if (y > 30) return -1;
			printf("%s\n", d[4]);
		}
		if (x == 10) printf("%s\n", d[6]);
		if (x == 11) {
			if (y > 30) return -1;
			printf("%s\n", d[2]);
		}
		if (x == 12) printf("%s\n", d[4]);
	}

	return 0;
}
