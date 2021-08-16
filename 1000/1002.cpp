#include <iostream>
using namespace std;

int sqr(int n) {
	return n * n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, r1, x2, y2, r2, sqrD;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		sqrD = sqr(x1 - x2) + sqr(y1 - y2);
		if (sqrD == 0 && r1 == r2)
			cout << "-1\n";
		else if (sqr(r1 + r2) == sqrD || sqr(r1 - r2) == sqrD)
			cout << "1\n";
		else if (sqr(r1 + r2) > sqrD && sqr(r1 - r2) < sqrD)
			cout << "2\n";
		else if (sqr(r1 + r2) < sqrD || sqrD < sqr(r1 - r2) || (sqrD == 0 && r1 != r2))
			cout << "0\n";
		else
			cout << "-1\n";
	}
}