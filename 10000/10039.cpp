#include <iostream>
using namespace std;

int main()
{
	int n, sum = 0;
	for (int i = 1; i <= 5; i++)
	{
		cin >> n;
		if (n < 40)
		{
			sum += 40;
		}
		else
		{
			sum += n;
		}
	}
	cout << sum / 5;
}