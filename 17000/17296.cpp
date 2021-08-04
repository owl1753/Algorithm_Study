#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#define MAX 1001

int main()
{
	double stage[MAX];
	int n, cnt = 0,flag = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &stage[i]);
	for (int i = 1; i <= n; i++)
	{
		if (stage[i] == 0)
			continue;
		if (stage[i] != (int)stage[i])
		{
			if (flag == 0)
				cnt += (int)stage[i] + 1;
			else
				cnt += (int)stage[i];
		}
		else
			cnt += (int)stage[i];
		flag = 1;
	}
	printf("%d", cnt);
}