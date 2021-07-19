#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

priority_queue<int> maxhip;
priority_queue<int> minhip;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int t;
		scanf("%d", &t);
		if (i % 2)
		{
			if (minhip.size() != NULL && -minhip.top() < t)
			{
				maxhip.push(-minhip.top());
				minhip.pop();
				minhip.push(-t);
			}
			else
				maxhip.push(t);
		}
		else
		{
			if (maxhip.size() != NULL && maxhip.top() > t)
			{
				minhip.push(-maxhip.top());
				maxhip.pop();
				maxhip.push(t);
			}
			else
				minhip.push(-t);
		}
		printf("%d\n", maxhip.top());
	}
}