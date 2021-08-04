#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#define ll long long

int main()
{
	ll k, now = -1, pre = -1, dis = 10, flag = 1;
	scanf("%lld", &k);
	while (k)
	{
		now = k % 10;
		if (pre != -1 && dis == 10)
			dis = now - pre;
		if (dis != 10 && now - pre != dis)
		{
			flag = 0;
			break;
		}
		pre = now;
		k /= 10;
	}
	if (flag == 1)
		printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
	else
		printf("흥칫뿡!! <(￣ ﹌ ￣)>");
}