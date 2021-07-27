#include <iostream>
using namespace std;

int main()
{
	int buger[3];
	int drink[2];
	int min = 999999999;
	cin >> buger[0];
	cin >> buger[1];
	cin >> buger[2];
	cin >> drink[0];
	cin >> drink[1];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (min > buger[i] + drink[j] - 50)
			{
				min = buger[i] + drink[j] - 50;
			}
		}
	}
	cout << min;
}