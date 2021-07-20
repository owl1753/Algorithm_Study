#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define MAX 101

char str[MAX];

int main()
{
	int x, y, sum = 0;
	scanf("%d%d", &x, &y);
	sum += y - 1;
	for (int i = 2; i <= x; i++)
	{
		switch (i - 1)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: sum += 31; break;
		case 4:
		case 6:
		case 9:
		case 11: sum += 30; break;
		case 2: sum += 28; break;
		}
	}
	switch (sum % 7)
	{
	case 0: printf("MON\n"); break;
	case 1: printf("TUE\n"); break;
	case 2: printf("WED\n"); break;
	case 3: printf("THU\n"); break;
	case 4: printf("FRI\n"); break;
	case 5: printf("SAT\n"); break;
	case 6: printf("SUN\n"); break;
	}
}