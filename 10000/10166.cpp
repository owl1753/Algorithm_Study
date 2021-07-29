#include <iostream>
using namespace std;
#define MAX 2001

int arr[MAX][MAX] = { 0 };
int d1, d2, cnt = 0;

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main()
{
	cin >> d1 >> d2;
	for (int i = d1; i <= d2; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int g = gcd(i, j);
			if (arr[j / g][i / g] == 0)
			{
				arr[j / g][i / g] = 1;
				cnt++;
			}
		}
	}
	cout << cnt;
}