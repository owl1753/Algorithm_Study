#include <iostream>
using namespace std;

int main()
{
	int arr[8];
	int state = 0;
	for (int i = 0; i < 8; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i < 8; i++)
	{
		if (arr[i] - arr[i - 1] == 1)
		{
			if (state == 0 || state == 1)
				state = 1;
			else
			{
				state = 3;
				break;
			}
		}
		else if (arr[i] - arr[i - 1] == -1)
		{
			if (state == 0 || state == 2)
				state = 2;
			else
			{
				state = 3;
				break;
			}
		}
		else
		{
			state = 3;
			break;
		}
	}
	if (state == 1)
		printf("ascending");
	else if (state == 2)
		printf("descending");
	else
		printf("mixed");
}