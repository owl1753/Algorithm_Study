#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, t, cnt = 0;
	cin >> n;
	t = n;
	while (1)
	{
		cnt++;
		t = ((t % 10) * 10) + (((t % 10) + (t / 10)) % 10);
		if (t == n)
		{
			break;
		}
	}
	cout << cnt;
}