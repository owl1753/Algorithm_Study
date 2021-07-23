#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	int rope[100001];
	int n, max = 0, cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> rope[i];
	}
	sort(rope, rope + n, compare);
	max = rope[0];
	for (int i = 1; i < n; i++)
	{
		cnt++;
		if (max / (double)cnt <= rope[i])
		{
			max = rope[i] * cnt;
		}
	}
	cout << max;
}