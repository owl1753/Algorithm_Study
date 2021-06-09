#include <iostream>
using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;
	if (m - 45 >= 0)
	{
		m -= 45;
	}
	else
	{
		if (h > 0)
		{
			h -= 1;
		}
		else
		{
			h = 23;
		}
		m = m + 15;
	}
	cout << h << " " << m;
}