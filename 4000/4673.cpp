#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int d(int n)
{
	int sum = n;
	while (1)
	{
		if (n == 0)
			return sum;
		sum += n % 10;
		n /= 10;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[10000] = { 0 };
	for (int i = 1; i <= 10000; i++)
	{
		int n = i;
		while (1)
		{
			n = d(n);
			if (n > 10000)
				break;
			arr[n - 1] = 1;
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (arr[i] == 0)
			cout << i + 1 << "\n";
	}
}