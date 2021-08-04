#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = n; i >= 0; i--)
	{
		if (i == 2)
		{
			printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
			printf("Take one down and pass it around, %d bottle of beer on the wall.\n\n", i - 1);
		}
		else if (i == 1)
		{
			printf("%d bottle of beer on the wall, %d bottle of beer.\n", i, i);
			printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
		}
		else if (i == 0)
		{
			if (n == 1)
			{
				printf("No more bottles of beer on the wall, no more bottles of beer.\n");
				printf("Go to the store and buy some more, %d bottle of beer on the wall.\n\n", n);
			}
			else
			{
				printf("No more bottles of beer on the wall, no more bottles of beer.\n");
				printf("Go to the store and buy some more, %d bottles of beer on the wall.\n\n", n);
			}
			
		}
		else
		{
			printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
			printf("Take one down and pass it around, %d bottles of beer on the wall.\n\n", i - 1);
		}
	}
}