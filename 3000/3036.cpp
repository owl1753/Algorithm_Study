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
	int n;
	cin >> n;
	int *r = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> r[i];
	}
	for (int i = 1; i < n; i++)
	{
		cout << r[0] / gcd(r[0], r[i]) << "/" << r[i] / gcd(r[0], r[i]) << endl;
	}
}