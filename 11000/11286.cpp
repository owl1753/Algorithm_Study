#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct compare{
	bool operator()(int a, int b){
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

priority_queue<int, vector<int>, compare> pq;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
			continue;
		}
		pq.push(x);
	}
}