#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char s[21];
	int t, r;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> r;
		cin >> s;
		for (int j = 0; s[j] != '\0'; j++)
		{
			for (int k = 0; k < r; k++)
			{
				cout << s[j];
			}
		}
		cout << "\n";
	}
}