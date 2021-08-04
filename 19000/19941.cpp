#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 20001

char ham[MAX];
int check[MAX];

int main()
{
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);
	scanf("%s", ham);
	for (int i = 0; ham[i] != '\0'; i++)
	{
		if (ham[i] == 'P')
		{
			for (int j = (i - k); j <= (i + k); j++)
			{
				if (ham[j] == 'H' && check[j] == 0)
				{
					cnt++;
					check[j] = 1;
					break;
				}
			}
		}
	}
	printf("%d", cnt);
}