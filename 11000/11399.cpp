#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, min = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			min += arr[j];
		}
	}
	cout << min;
}