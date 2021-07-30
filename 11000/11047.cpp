#include <iostream>
using namespace std;

int main()
{
	int arr[10];
	int n, k, min = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		min += k / arr[i];
		if (k % arr[i] == 0)
		{
			break;
		}
		k %= arr[i];
	}
	cout << min;
}