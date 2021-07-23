#include <iostream>
using namespace std;

int main()
{
	int arr[300][300];
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> k;
	while (k != 0)
	{
		int startx, starty, endx, endy, sum = 0;
		cin >> startx >> starty >> endx >> endy;
		for (int i = startx - 1; i < endx; i++)
		{
			for (int j = starty - 1; j < endy; j++)
			{
				sum += arr[i][j];
			}
		}
		cout << sum << "\n";
		k--;
	}
}