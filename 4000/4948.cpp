#include <iostream>
#include <math.h>
using namespace std;
#define MAX 246913

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
	while(1)
	{
		int n, cnt = 0;
		cin >> n;
		if (n == 0)
			break;
		for (int j = n + 1; j <= (2 * n); j++)
		{
			if (check[j] == 0)
				cnt++;
		}
		cout << cnt << "\n";
	}
}