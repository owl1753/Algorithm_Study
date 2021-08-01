#include <iostream>
using namespace std;
#include <queue>

int main()
{
	queue<int> q;
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		q.push(i);
	printf("<");
	while (!q.empty())
	{
		for (int i = 1; i < k; i++)
		{
			int t = q.front();
			q.pop();
			q.push(t);
		}
		if (q.size() == 1)
			printf("%d>", q.front());
		else
			printf("%d, ", q.front());
		q.pop();
	}
}