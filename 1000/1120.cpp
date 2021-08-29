#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define INF 987654321

string a;
string b;
int l, r, result = INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a;
	cin >> b;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[j + i])
				cnt++;
		}
		result = min(result, cnt);
	}
	cout << result;
}