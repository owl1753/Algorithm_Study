#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define MAX 101

char str[MAX];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
			printf(" ");
		for (int j = i; j <= n; j++)
			printf("*");
		printf("\n");
	}
}