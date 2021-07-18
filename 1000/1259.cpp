#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		int arr[5];
		int n, size = 0, flag = 1;
		scanf("%d", &n);
		if (n == 0)
			break;
		while (n)
		{
			arr[size] = n % 10;
			n /= 10;
			size++;
		}
		size--;
		for (int i = 0; i <= size; i++)
		{
			if (arr[i] != arr[size - i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			printf("yes\n");
		else
			printf("no\n");
	}

}