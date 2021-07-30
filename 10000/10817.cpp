#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	if ((a >= b && a <= c) || (a >= c && a <= b))
	{
		cout << a;
	}
	else if ((b >= a && b <= c) || (b >= c && b <= a))
	{
		cout << b;
	}
	else if ((c >= a && c <= b) || (c >= b && c <= a))
	{
		cout << c;
	}
}