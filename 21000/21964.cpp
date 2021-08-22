#include <iostream>
#include <string>
using namespace std;

string s;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> s;
	for (int i = n - 5; i < n; i++) {
		cout << s[i];
	}
}