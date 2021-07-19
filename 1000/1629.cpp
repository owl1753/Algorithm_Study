#include <iostream>
using namespace std;
#define ll long long

ll pow(ll a, ll b, ll c) {
	int result = 1;
	while (b) {
		if (b % 2)
			result = (result * a) % c;
		a = (a * a) % c;
		b /= 2;
	}
	return result;
}

int main() {
	ll a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld", pow(a, b, c));
}