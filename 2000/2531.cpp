#include <iostream>
using namespace std;

int sushi[30010];
int check[3010];

int main()
{
	int N, d, k, c, cnt = 0, max = 0;
	cin >> N >> d >> k >> c;
	for (int i = 1; i <= N; i++)
		cin >> sushi[i];
	for (int i = 1; i < N + k; i++)
	{
		if (i <= N)
		{
			check[sushi[i]]++;
			if (i > k)
				check[sushi[i - k]]--;
		}
		else
		{
			check[sushi[i - N]]++;
			check[sushi[i - k]]--;
		}
		for (int j = 1; j <= d; j++)
		{
			if (check[j] >= 1)
				cnt++;
			else if (j == c)
				cnt++;
		}
		if (max < cnt)
			max = cnt;
		cnt = 0;
	}
	cout << max;
}