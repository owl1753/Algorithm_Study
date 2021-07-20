#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int A[MAX];
int n, m;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	scanf("%d", &m);
	sort(A, A + n);
	for (int i = 1; i <= m; i++)
	{
		int k, left = 0, right = n - 1, mid, flag = 0;
		scanf("%d", &k);
		while (left <= right)
		{
			mid = (right + left) / 2;
			if (A[mid] == k)
			{
				flag = 1;
				break;
			}
			if (A[mid] < k)
				left = mid + 1;
			else
				right = mid - 1;
		}
		printf("%d\n", flag);
	}
}