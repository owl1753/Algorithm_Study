#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int q, a;

int main()
{
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &a);
		if ((a & (-a)) == a)
			printf("1\n");
		else
			printf("0\n");
	}
}