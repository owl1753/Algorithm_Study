#include <iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main() {
	ll x, y;
	scanf("%lld%lld", &x, &y);
	printf("%lld", (x + y) - gcd(x, y));
}