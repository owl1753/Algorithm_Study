#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char s[16];
	int sum = 0;
	cin >> s;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'Z')
		{
			sum += 10;
		}
		else if (s[i] >= 'S')
		{
			sum += ((s[i] - 66) / 3) + 3;
		}
		else
		{
			sum += ((s[i] - 65) / 3) + 3;
		}
	}
	cout << sum;
}