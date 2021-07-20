#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 101

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int arr[MAX];
		int check[MAX] = { 0, };
		queue<pair<int, int>> q;
		int n, m, cnt = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			q.push(make_pair(arr[i], i));
		}
		while (!q.empty())
		{
			int k = q.front().first;
			int index = q.front().second;
			int flag = 1;
			q.pop();
			for (int i = 0; i < n; i++)
			{
				if (k < arr[i] && check[i] == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				check[index] = 1;
				cnt++;
				if (index == m)
					break;
			}
			else {
				q.push(make_pair(k, index));
			}
		}
		printf("%d\n", cnt);
	}
}