#include <iostream>
using namespace std;
#define MAX 51
#define M 1234567891
#define R 31
#define ll long long

ll hashing(char* str, int l)
{
	ll sum = 0;
	ll r = 1;
	for (int i = 0; i < l; i++)
	{
		sum = (sum + ((str[i] - 'a' + 1) * r)) % M;
		r = (r * R) % M;
	}
	return sum % M;
}

int main()
{
	char str[MAX];
	int l;
	scanf("%d", &l);
	scanf("%s", str);
	printf("%lld", hashing(str, l));
}