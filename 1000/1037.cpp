#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int n, mmax = 0, mmin = INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		mmax = max(mmax, k);
		mmin = min(mmin, k);
	}
	cout << mmax * mmin;
}