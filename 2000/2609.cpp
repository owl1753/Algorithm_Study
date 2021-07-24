#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	return gcd(b, a % b);
}
int main()
{
	int a, b, g;
	cin >> a >> b;
	g = gcd(a, b);
	cout << g << endl;
	cout << (a / g) * (b / g) * g << endl;
	return 0;
}