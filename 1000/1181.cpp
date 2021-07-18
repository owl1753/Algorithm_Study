#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str[20001];
int n;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str + n, compare);
	for (int i = 0; i < n; i++) {
		if (str[i] != str[i + 1])
			cout << str[i] << "\n";
	}
}
