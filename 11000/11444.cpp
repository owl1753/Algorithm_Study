#include <iostream>
#include <map>
using namespace std;
#define MOD 1000000007

map<long long, long long> m;

long long func(long long n) {
	if (m.find(n) != m.end()) return m[n];

	long long a = func(n / 2 - 1) % MOD;
	long long b = func(n / 2) % MOD;
	long long c = func(n / 2 + 1) % MOD;

	if (n % 2) m.insert(make_pair(n, (c * c + b * b) % MOD));
	else m.insert(make_pair(n, (b * c + a * b) % MOD));

	return m[n];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n;
	cin >> n;
	m.insert(make_pair(0, 0));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 1));
	cout << func(n);
}