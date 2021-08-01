#include <iostream>
using namespace std;
#define ll long long
#define MOD 1000000007

ll pow(ll a, ll x) {
	ll result = 1;
	while (x) {
		if (x % 2){
			result *=a;
			result %= MOD;
		}
		a = (a * a) % MOD;
		x /= 2;
	}
	return result;
}

int main() {
	ll a, x;
	scanf("%lld%lld", &a, &x);
	a %= MOD;
	printf("%lld", pow(a, x));
}