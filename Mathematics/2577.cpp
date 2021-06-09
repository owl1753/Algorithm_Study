#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[10] = { 0 };
	int a, b, c, mul;
	cin >> a >> b >> c;
	mul = a * b * c;
	while (1)
	{
		if (mul == 0)
			break;
		arr[mul % 10]++;
		mul /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\n";
	}
}