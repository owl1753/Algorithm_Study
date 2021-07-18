#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAX 21

int arr[MAX];
int N, S, flag, cnt = 0;

void func(int n, int sum, int flag)
{
	if (sum == S && flag == 1)
		cnt++;
	if (n == 0)
		return;
	func(n - 1, sum + arr[n], 1);
	func(n - 1, sum, 0);
}

int main()
{
	scanf("%d%d", &N, &S);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	func(N, 0, 0);
	printf("%d", cnt);
}