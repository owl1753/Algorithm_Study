#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char s[1000000];
	int alpha[26] = { 0 };
	int max = -1, flag = 0;
	cin >> s;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 97)
			alpha[s[i] - 'a']++;
		else
			alpha[s[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] > alpha[max])
		{
			max = i;
			flag = 0;
		}
		else if (alpha[i] == alpha[max])
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		cout << "?";
	}
	else
	{
		cout << (char)('A' + max);
	}
}