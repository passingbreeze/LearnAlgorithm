#include <cstdio>

class aplusb {
	int a = 0;
	int b = 0;
public:
	aplusb(int _a, int _b): a(_a), b(_b) {}
	int add() const {
		return a + b;
	}

};

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	aplusb c(a, b);
	printf("%d\n", c.add());
	return 0;
}