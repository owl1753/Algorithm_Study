#include <stdio.h>
#pragma warning(disable:4996)

void move(int from, int to) 
{
	printf("\n%d %d", from, to);
}

void hanoi(int n, int from, int other, int to)
{
	if (n == 1)
	{
		move(from, to);
		return;
	}
	else
	{
		hanoi(n - 1, from, to, other);
		move(from, to);
		hanoi(n - 1, other, from, to);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", (1 << n) - 1);
	hanoi(n, 1, 2, 3);
}