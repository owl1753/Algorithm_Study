#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0, mheight = 0, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		if (k > mheight)
		{
			mheight = k;
			cnt = 0;
		}
		else
		{
			cnt++;
		}
		if (max < cnt)
			max = cnt;
	}
	printf("%d", max);
}