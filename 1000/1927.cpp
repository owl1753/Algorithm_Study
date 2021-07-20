#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int main()
{
	priority_queue<int> pq;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		if (x != 0)
			pq.push(-x);
		else
		{
			if (pq.size() == NULL)
				printf("0\n");
			else
			{
				printf("%d\n", -pq.top());
				pq.pop();
			}
		}
	}
}