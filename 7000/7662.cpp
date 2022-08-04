#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		map<int, int> m;
		priority_queue<int> pq1;
		priority_queue<int, vector<int>, greater<int>> pq2;
		int k;
		cin >> k;
		while (k--) {
			char ch;
			cin >> ch;
			if (ch == 'I') {
				int tmp;
				cin >> tmp;
				pq1.push(tmp);
				pq2.push(tmp);
				if (m.find(tmp) != m.end()) m[tmp]++;
				else m.insert(make_pair(tmp, 1));
			}
			else if (ch == 'D') {
				int tmp;
				cin >> tmp;
				if (tmp == 1) {
					while (true) {
						if (pq1.empty()) break;

						if (m[pq1.top()] > 0) {
							m[pq1.top()]--;
							pq1.pop();
							break;
						}
						else pq1.pop();
					}
					
				}
				else if (tmp == -1) {
					while (true) {
						if (pq2.empty()) break;

						if (m[pq2.top()] > 0) {
							m[pq2.top()]--;
							pq2.pop();
							break;
						}
						else pq2.pop();
					}
				}
			}
		}
		while (true) {
			if (pq1.empty() || pq2.empty()) {
				cout << "EMPTY\n";
				break;
			}

			if (m[pq1.top()] > 0 && m[pq2.top()] > 0) {
				cout << pq1.top() << " " << pq2.top() << "\n";
				break;
			}
			else if (m[pq1.top()] <= 0) pq1.pop();
			else if (m[pq2.top()] <= 0) pq2.pop();
		}
	}
}