#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int e, s, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> e >> s >> m;
	for (int i = 1; ; i++) {
		if ((i % 15 == e || (i % 15 == 0 && e == 15)) && (i % 28 == s || (i % 28 == 0 && s == 28)) && (i % 19 == m || (i % 19 == 0 && m == 19))) {
			cout << i;
			break;
		}
	}
}