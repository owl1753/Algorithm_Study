#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	return gcd(b, a % b);
}
int main()
{
	int t, n;
	cin >> t;
	long long *sum = new long long[t];
	for (int i = 0; i < t; i++)
	{
		sum[i] = 0;
	}
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		long long *arr = new long long[n];
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
		}
		for (int j = 0; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum[i] += gcd(arr[j], arr[k]);
			}
		}
		delete[] arr;
	}
	for (int i = 0; i < t; i++)
	{
		cout << sum[i] << endl;
	}
	delete[] sum;
}