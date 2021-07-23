#include <iostream>
using namespace std;

int main()
{
	long long n, sum = 0;
	cin >> n;
	for (long long i = 1; ; i++)
	{
		sum += 6 * i;
		if (n == 1)
		{
			cout << 1;
			break;
		}
		else if (n - 1 - sum <= 0)
		{
			cout << i + 1;
			break;
		}
	}
}