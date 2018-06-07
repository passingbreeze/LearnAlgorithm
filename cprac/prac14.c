#include <stdio.h>

int find(int* a, int n, int v)
{
	int i;
	for (i = n - 1; i >= 0 && !(a[i] == v); --i)
		;
	return i;
}

int main(int argc, char const *argv[])
{
	int a[1024];
	int num = 0, i = 0, value = 0;

	scanf("%d", &num);
	for (i = 0; i < num; ++i)
		scanf("%d", a + i);
	scanf("%d", &value);

	i = find(a, num, value);

	if (i < 0)
		printf("not found: %d\n", i);
	else
		printf("found: %d\n", i);
	return 0;
}