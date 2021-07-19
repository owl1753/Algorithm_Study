#include <iostream>
using namespace std;

int main()
{
	char s[101];
	int n, flag = 0, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char alpah[26] = { 0 };
		cin >> s;
		for (int j = 0; s[j] != '\0'; j++)
		{
			if (alpah[s[j] - 'a'] == 1)
			{
				flag = 1;
				break;
			}
			if (s[j - 1] != s[j])
			{
				alpah[s[j - 1] - 'a'] = 1;
			}
		}
		if (flag == 0)
		{
			cnt++;
		}
		flag = 0;
	}
	cout << cnt;
}