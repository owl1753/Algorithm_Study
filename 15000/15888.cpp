#pragma warning(disable:4996)
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000001

int check[MAX];
int a, b, c;

int main()
{
	for (int i = 2; i <= MAX; i*=2)
		check[i] = 1;
	scanf("%d%d%d", &a, &b, &c);
	if ((-b + (int)sqrt((b*b) - (4 * a * c))) % (2 * a) == 0 && (-b - (int)sqrt((b*b) - (4 * a * c))) % (2 * a) == 0 
		&& (b*b) - (4 * a * c) > 0 && (int)sqrt((b*b) - (4 * a * c)) * (int)sqrt((b*b) - (4 * a * c)) == (b*b) - (4 * a * c))
	{
		if (check[(-b + (int)sqrt((b*b) - (4 * a * c))) / (2 * a)] == 1 && check[(-b - (int)sqrt((b*b) - (4 * a * c))) / (2 * a)] == 1)
			printf("이수근");
		else
			printf("정수근");
	}
	else
		printf("둘다틀렸근");
}