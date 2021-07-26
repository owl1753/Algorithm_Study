#include <iostream>
using namespace std;
#define MAX 15

int main()
{
	int apart[MAX][MAX];
	for (int i = 1; i < MAX; i++)
	{
		apart[0][i] = i;
	}
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			if (j == 1)
				apart[i][j] = 1;
			else
				apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
		}
	}
	int t, k, n;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> k >> n;
		cout << apart[k][n] << "\n";
	}
}