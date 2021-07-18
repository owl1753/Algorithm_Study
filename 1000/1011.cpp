#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		long long x, y, left = 0, right = 0, sum = 0;
		cin >> x >> y;
		while (1)
		{
			if (left == right)
			{
				left++;
				sum += left;
			}
			else
			{
				right++;
				sum += right;
			}
			if (y - x <= sum)
				break;
		}
		cout << left + right << "\n";
	}
}