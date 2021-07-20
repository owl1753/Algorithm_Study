#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define MAX 100001

priority_queue<int> pq;
int arr[MAX];

int main()
{
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		pq.push(-x);
	}
	while (pq.size() != NULL)
	{
		int plus = 0;
		plus += -pq.top();
		pq.pop();
		if (pq.size() == NULL)
			break;
		plus += -pq.top();
		pq.pop();
		cnt += plus;
		if (pq.size() == NULL)
			break;
		pq.push(-plus);
	}
	printf("%d", cnt);
}