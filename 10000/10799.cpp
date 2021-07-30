#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<char> s;
	char str[100010];
	long long sum = 0;
	cin >> str;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (s.top() == '(')
			{
				s.pop();
				if (str[i - 1] == ')')
					sum += 1;
				else
					sum += s.size();
			}
		}
	}
	cout << sum;
}