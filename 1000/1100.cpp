#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#define MAX 8

int main()
{
	char ch;
	int cnt = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			scanf(" %c", &ch);
			if (i % 2 == j % 2 && ch == 'F')
				cnt++;
		}
	}
	printf("%d", cnt);
}