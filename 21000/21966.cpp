#include <iostream>
#include <string>
using namespace std;

string s;
int n, flag = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> s;
	if (n <= 25) {
		cout << s;
	}
	else {
		for (int i = 11; i < n - 12; i++) {
			if (s[i] == '.') {
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			for (int i = 0; i < 11; i++)
				cout << s[i];
			cout << "...";
			for (int i = n - 11; i < n; i++)
				cout << s[i];
		}
		else {
			for (int i = 0; i < 9; i++)
				cout << s[i];
			cout << "......";
			for (int i = n - 10; i < n; i++)
				cout << s[i];
		}
	}
}