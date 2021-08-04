#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10010

int s[MAX];
int m = 987654321;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < (n * 2); i++)
	{
		scanf("%d", &s[i]);
	}
	sort(s, s + (n * 2));
	for (int i = 0; i < n; i++)
	{
		int t = s[i] + s[(n * 2) - i - 1];
		if (m > t)
			m = t;
	}
	printf("%d", m);
}