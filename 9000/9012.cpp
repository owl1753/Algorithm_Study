#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int t, cnt = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		stack<char> s;
		char ch[51];
		cin >> ch;
		for (int i = 0; ch[i] != NULL; i++)
		{
			s.push(ch[i]);
		}
		while (s.size() != NULL)
		{
			if (s.top() == '(' && cnt == 0)
			{
				cnt = 1;
				break;
			}
			else if (s.top() == '(')
			{
				cnt++;
			}
			else if (s.top() == ')')
			{
				cnt--;
			}
			s.pop();
		}
		if (cnt == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
		cnt = 0;
	}
}