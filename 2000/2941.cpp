#include <iostream>
using namespace std;

int main()
{
	char s[101];
	int cnt = 0;
	cin >> s;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '=')
		{
			if (s[i - 1] == 'z' && s[i - 2] == 'd')
			{
				cnt -= 2;
			}
			else if (s[i - 1] == 'c' || s[i - 1] == 's' || s[i - 1] == 'z')
			{
				cnt--;
			}
		}
		else if (s[i] == '-')
		{
			if (s[i - 1] == 'c' || s[i - 1] == 'd')
			{
				cnt--;
			}
		}
		else if (s[i] == 'j')
		{
			if (s[i - 1] == 'n' || s[i - 1] == 'l')
			{
				cnt--;
			}
		}
		cnt++;
	}
	cout << cnt;
}