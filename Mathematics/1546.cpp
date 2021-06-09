#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.tie(NULL);
	cout.tie(NULL);
	int arr[1000];
	double total = 0;
	int n, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		total += (((double)arr[i] / (double)max) * 100.0);
	}
	cout << fixed;
	cout.precision(6);
	cout << total / n;
}