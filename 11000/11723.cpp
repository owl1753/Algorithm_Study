#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int s = 0, m;
	cin >> m;
	while (m--) {
		string ch;
		int x;
		cin >> ch;
		if (ch == "add") {
			cin >> x;
			s |= (1 << x);
		}
		else if (ch == "remove") {
			cin >> x;
			s &= (-1 ^ (1 << x));
		}
		else if (ch == "check") {
			cin >> x;
			if (s & (1 << x))
				cout << "1\n";
			else
				cout << "0\n";

		}
		else if (ch == "toggle") {
			cin >> x;
			s ^= (1 << x);
		}
		else if (ch == "all") {
			s = (1 << 20 + 1) - 1;
		}
		else if (ch == "empty") {
			s = 0;
		}
	}
}