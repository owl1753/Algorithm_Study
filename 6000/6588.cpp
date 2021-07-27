#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000001

int check[MAX] = { 0 };

int main()
{
	check[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		if (check[i] == 1)
			continue;
		for (int j = i + i; j < MAX; j += i)
			check[j] = 1;
	}
	while (1) {
		int n, a = 0, b = 0;
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 3; i < n; i+=2) {
			if (check[i] == 1 || check[n - i] == 1)
				continue;
			a = i;
			b = n - i;
			break;
		}
		printf("%d = %d + %d\n", n, a, b);
	}
}