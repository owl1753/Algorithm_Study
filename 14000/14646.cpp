#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int check[MAX];

int main()
{
	int N, K, cnt = 0, m = 0;
	scanf("%d", &N);
	N *= 2;
	while(N--)
	{
		scanf("%d", &K);
		if (check[K] == 1)
			cnt--;
		else
		{
			cnt++;
			check[K] = 1;
		}
		m = max(m, cnt);
	}
	printf("%d", m);
}