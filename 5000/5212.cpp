#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#define MAX 10

int map[MAX][MAX];
int check[MAX][MAX];
int R, C, cnt = 0;

int main()
{
	int x1 = 987654321, y1 = 987654321, x2 = 0, y2 = 0;
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf(" %c", &map[i][j]);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{

			if (map[i - 1][j] == '.' || (i - 1) < 0)
				cnt++;
			if (map[i + 1][j] == '.' || (i + 1) >= R)
				cnt++;
			if (map[i][j - 1] == '.' || (j - 1) < 0)
				cnt++;
			if (map[i][j + 1] == '.' || (j + 1) >= C)
				cnt++;
			if (cnt >= 3 || map[i][j] == '.')
				check[i][j] = 1;
			cnt = 0;
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (check[i][j] == 0)
			{
				if (x1 > i)
					x1 = i;
				if (y1 > j)
					y1 = j;
				if (x2 < i)
					x2 = i;
				if (y2 < j)
					y2 = j;
			}
		}
	}
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			if (check[i][j] == 1)
				printf(".");
			else
				printf("X");
		}
		printf("\n");
	}
}