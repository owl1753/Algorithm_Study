#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int queue[10010] = { NULL }, n, front = 0, back = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string ch;
		cin >> ch;
		if (ch == "push")
		{
			int t;
			cin >> t;
			queue[back++] = t;
		}
		else if (ch == "pop")
		{
			if (back - front != 0)
				cout << queue[front++] << "\n";
			else
				cout << -1 << "\n";
		}
		else if (ch == "size")
		{
			cout << back - front << "\n";
		}
		else if (ch == "empty")
		{
			if (back - front == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (ch == "front")
		{
			if (back - front != 0)
				cout << queue[front] << "\n";
			else
				cout << -1 << "\n";
		}
		else if (ch == "back")
		{
			if (back - front != 0)
				cout << queue[back - 1] << "\n";
			else
				cout << -1 << "\n";
		}
	}
}