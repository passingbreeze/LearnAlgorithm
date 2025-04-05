#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x = 351;
	int* p;

	p = &x;
	printf("&x is %p\n", &x);
	printf("p is %p\n", p);
	printf("x is %d\n", x);

	*p = 333;
	printf("x is %d\n", x);
	return 0;
}