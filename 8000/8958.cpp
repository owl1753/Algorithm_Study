#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.tie(NULL);
	cout.tie(NULL);
	char OX[81];
	int t, score = 0, cnt = 1;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> OX;
		for (int j = 0; OX[j] != '\0'; j++)
		{
			if (OX[j] == 'O')
			{
				if (j != 0)
				{
					if (OX[j - 1] == 'O')
						cnt++;
					else
						cnt = 1;
				}
				score += cnt;
			}
		}
		cout << score << "\n";
		score = 0;
		cnt = 1;
	}
}