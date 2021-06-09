#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define MAX 101

char str[MAX];

int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < n; i++)
		sum += str[i] - '0';
	printf("%d", sum);
}