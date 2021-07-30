#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char s[101];
	int pos = -1;
	cin >> s;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; s[j] != '\0'; j++)
		{
			if (s[j] == 'a' + i)
			{
				pos = j;
				break;
			}
		}
		cout << pos << " ";
		pos = -1;
	}
}