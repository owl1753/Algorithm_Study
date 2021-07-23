#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1001

int main()
{
	int check[MAX] = { 0 };
	int n, cnt = 0;
	cin >> n;
	check[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		if (check[i] == 1)
			continue;
		for (int j = i + i; j <= 1000; j += i)
			check[j] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		if (check[t] == 0)
			cnt++;
	}
	cout << cnt;
}