#pragma warning(disable:4996)
#include <iostream>
using namespace std;

long long arr[1000000];
int n, m, length, r = 0, l = 0;

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > r)
			r = arr[i];
	}

	length = r / 2;
	while (1)
	{
		long long sum = 0;
		if (r == length || l == length)
			break;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > length)
			{
				sum += arr[i] - length;
			}
		}
		if (sum == m)
		{
			break;
		}
		else if (sum > m)
		{
			l = length;
			length = (l + r) / 2;
		}
		else
		{
			r = length;
			length = (l + r) / 2;
		}
	}
	printf("%d", length);
}