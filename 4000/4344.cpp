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
	int c, total = 0, cnt = 0;
	cin >> c;
	cout << fixed;
	cout.precision(3);
	for (int i = 1; i <= c; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
			total += arr[j];
		}
		for (int j = 0; j < n; j++)
		{
			if (arr[j] > (total / n))
			{
				cnt++;
			}
		}
		cout << (cnt / (double)n) * 100 << "%\n";
		total = 0;
		cnt = 0;
	}
}