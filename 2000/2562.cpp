#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[9];
	int max;
	int cnt = 1;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}
	max = arr[0];
	for (int i = 1; i < 9; i++)
	{
		if (max <= arr[i])
		{
			max = arr[i];
			cnt = i + 1;
		}
	}
	cout << max << "\n" << cnt;
}