#define MAX 6562
#include <iostream>
using namespace std;

char arr[MAX][MAX];

void star(int n, int a, int b)
{
	for (int i = a; i < n + a; i += (n / 3))
	{
		for (int j = b; j < n + b; j += (n / 3))
		{
			if (i == a || i == n + a - (n / 3) || j == b || j == n + b - (n / 3))
			{
				if (n == 3)
					arr[i][j] = '*';
				else
					star(n / 3, i, j);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = ' ';
		}
	}
	star(n, 0, 0);
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", arr[i]);
	}
}