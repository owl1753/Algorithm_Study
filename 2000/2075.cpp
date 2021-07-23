#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define MAX 1501

priority_queue<int> pq;

int main()
{
	int N, t;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &t);
		pq.push(-t);
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &t);
			if (t > -pq.top())
			{
				pq.pop();
				pq.push(-t);
			}
		}
	}
	printf("%d", -pq.top());
}