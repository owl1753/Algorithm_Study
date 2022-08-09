#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;
	stack<pair<char, int>> s;
	int cnt = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') { cout << str[i]; }
		else if (str[i] == '(') cnt++;
		else if (str[i] == ')') {
			while (!s.empty() && cnt <= s.top().second) {
				cout << s.top().first;
				s.pop();
			}
			cnt--;
		}
		else {
			while (!s.empty() && cnt <= s.top().second) {
				if (str[i] == '+' || str[i] == '-' || s.top().first == '*' || s.top().first == '/') {
					cout << s.top().first;
					s.pop();
				}
				else {
					break;
				}
			}
			s.push(make_pair(str[i], cnt));
		}
	}
	while (!s.empty()) {
		cout << s.top().first;
		s.pop();
	}
}