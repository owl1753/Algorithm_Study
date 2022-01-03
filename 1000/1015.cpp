#include <iostream>
#include <algorithm>
using namespace std;

struct Pair {
	int c;
	int index;
};

bool cmp(Pair x, Pair y) {
	if (x.c == y.c)
		return x.index < y.index;
	return x.c < y.c;
}

Pair a[99];
int result[99];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].c;
		a[i].index = i;
	}


	sort(a, a + n, cmp);

	for (int i = 0; i < n; i++)
		result[a[i].index] = i;

	for (int i = 0; i < n; i++)
		cout << result[i] << " ";

}