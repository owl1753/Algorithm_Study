#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define MAX 500001

vector<string> result;
string name1[MAX];
string name2[MAX];
int n, m, cnt = 0;

int search(string k) {
	int left = 0, right = m - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (name2[mid] == k)
			return 1;
		if (name2[mid] < k)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> name1[i];
	for (int i = 0; i < m; i++)
		cin >> name2[i];
	sort(name1, name1 + n);
	sort(name2, name2 + m);
	for (int i = 0; i < n; i++) {
		if (search(name1[i])) {
			cnt++;
			result.push_back(name1[i]);
		}
	}
	cout << cnt << "\n";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";
}