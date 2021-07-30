#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= (n / 2) + (n % 2); j++)
		{
			printf("* ");
		}
		printf("\n ");
		for (int j = 1; j <= (n / 2); j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}