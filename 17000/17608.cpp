#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		if (i != 1)
		{
			while (s.size() != NULL)
			{
				if (s.top() > t)
					break;
				s.pop();
			}
		}
		s.push(t);
	}
	cout << s.size();
}