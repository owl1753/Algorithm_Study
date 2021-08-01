#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#define MAX 501

int bingo[MAX][MAX];
int n, m, nine = 0, cnt = 0, M = 0;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &bingo[i][j]);
			int t = bingo[i][j];
			while (t)
			{
				if (t % 10 == 9)
					nine++;
				t /= 10;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int t = bingo[i][j];
			while (t)
			{
				if (t % 10 == 9)
					cnt++;
				t /= 10;
			}
		}
		M = M > cnt ? M : cnt;
		cnt = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int t = bingo[j][i];
			while (t)
			{
				if (t % 10 == 9)
					cnt++;
				t /= 10;
			}
		}
		M = M > cnt ? M : cnt;
		cnt = 0;
	}
	printf("%d", nine - M);
}