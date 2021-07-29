#include <iostream>
using namespace std;

int main()
{
	int sum = 10;
	char arr[51];
	cin >> arr;
	for (int i = 1; arr[i] != '\0'; i++)
	{
		if (arr[i - 1] == arr[i])
			sum += 5;
		else
			sum += 10;
	}
	cout << sum;
}