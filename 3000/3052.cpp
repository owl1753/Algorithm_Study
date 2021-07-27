#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[10];
	int brr[10] = { 0 };
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
		arr[i] %= 42;
	}
	for (int i = 0; i < 10 - cnt; i++)
	{
		if (brr[i] != 1)
		{
			for (int j = i + 1; j < 10; j++)
			{
				if (arr[i] == arr[j])
				{
					brr[j] = 1;
					cnt++;
				}
			}
		}
	}
	cout << 10 - cnt;
}