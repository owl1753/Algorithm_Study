#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#define MAX 101

int color[MAX];
int P, N, r =0, g = 0, b = 0;

int main()
{
	scanf("%d%d", &P, &N);
	while(N--)
	{
		int pos;
		char direct;
		scanf("%d %c", &pos, &direct);
		while (pos != 0 && pos != 101)
		{
			if (direct == 'R')
				pos++;
			else
				pos--;
			color[pos]++;
		}
	}
	for (int i = 1; i < MAX; i++)
	{
		if (color[i] % 3 == 0)
			b++;
		if (color[i] % 3 == 1)
			r++;
		if (color[i] % 3 == 2)
			g++;
	}
	printf("%.2lf\n", P * (b / 100.0));
	printf("%.2lf\n", P * (r / 100.0));
	printf("%.2lf\n", P * (g / 100.0));
}