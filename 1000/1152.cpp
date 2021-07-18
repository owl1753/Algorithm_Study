#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char s[1000001];
	int cnt = 0;
	cin.getline(s, 1000001);
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (i == 0 && s[i] != 32)
		{
			cnt++;
		}
		else if (i != 0 && s[i - 1] == 32)
		{
			cnt++;
		}
	}
	cout << cnt;
}