#include <iostream>
#include <map>
using namespace std;

map<char, pair<char, char>> tree;
int n;

void func1(char here) {
	cout << here;
	if (tree[here].first != '.') func1(tree[here].first);
	if (tree[here].second != '.') func1(tree[here].second);
}

void func2(char here) {
	if (tree[here].first != '.') func2(tree[here].first);
	cout << here;
	if (tree[here].second != '.') func2(tree[here].second);
}

void func3(char here) {
	if (tree[here].first != '.') func3(tree[here].first);
	if (tree[here].second != '.') func3(tree[here].second);
	cout << here;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree.insert(make_pair(a, make_pair(b, c)));
	}
	func1('A');
	cout << "\n";
	func2('A');
	cout << "\n";
	func3('A');
}