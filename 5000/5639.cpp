#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> arr;
vector<pair<int, int>> s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (true) {
		int tmp;
		cin >> tmp;
		if (cin.eof()) break;
		arr.push_back(tmp);
	}
	for (int i = 0; i < arr.size(); i++) {
		if (s.empty()) s.push_back(make_pair(arr[i], 1));
		else if (s[s.size() - 1].first > arr[i]) s.push_back(make_pair(arr[i], s[s.size() - 1].second + 1));
		else {
			int depth = 2;
			for (int j = 0; j < s.size() - 1; j++) {
				if (s[j + 1].first > s[j].first && arr[i] > s[j].first) depth++;
				else if (s[j + 1].first < s[j].first && arr[i] < s[j].first) depth++;
				else break;
			}
			while (true) {
				pair<int, int> tmp = s[s.size() - 1];
				s.pop_back();

				if (tmp.second < depth) {
					s.push_back(tmp);
					s.push_back(make_pair(arr[i], depth));
					break;
				}

				cout << tmp.first << "\n";
			}
		}
	}
	while (!s.empty()) {
		cout << s[s.size() - 1].first << "\n";
		s.pop_back();
	}
}