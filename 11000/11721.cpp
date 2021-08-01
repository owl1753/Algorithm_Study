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
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++)
	{
		printf("%c", str[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
}