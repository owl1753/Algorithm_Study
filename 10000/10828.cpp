#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 10010

int stack[MAX];

int main()
{
	int N, top = 0, size = 0;
	char cmd[100];
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", cmd);
		if (!strcmp("push", cmd))
		{
			int t;
			scanf("%d", &t);
			stack[top] = t;
			top++;
		}
		if (!strcmp("pop", cmd))
		{
			if (top == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", stack[top - 1]);
				top--;
			}
		}
		if (!strcmp("size", cmd))
			printf("%d\n", top);
		if (!strcmp("empty", cmd))
		{
			if (top == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		if (!strcmp("top", cmd))
		{
			if (top == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", stack[top - 1]);
			}
		}
	}
}