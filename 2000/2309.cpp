#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int nanjang[9], sum = 0, false1, false2;
	for (int i = 0; i < 9; i++)
	{
		cin >> nanjang[i];
		sum += nanjang[i];
	}
	sort(nanjang, nanjang + 9);
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (nanjang[i] + nanjang[j]) == 100)
			{
				false1 = i;
				false2 = j;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i != false1 && i != false2)
		{
			cout << nanjang[i] << endl;
		}
	}
}