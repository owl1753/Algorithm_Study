#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000001

int check[MAX] = { 0 };

int main()
{
	int m, n, cnt = 0;
	cin >> m >> n;
	check[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		if (check[i] == 1)
			continue;
		for (int j = i + i; j < MAX; j += i)
			check[j] = 1;
	}
	for (int i = m; i <= n; i++)
	{
		if (check[i] == 0)
			cout << i << "\n";
	}
}