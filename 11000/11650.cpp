#include <iostream>
#include <algorithm>
using namespace std;

struct Pos {
	int x, y;
};

bool compare(Pos a, Pos b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

Pos p[100001];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	sort(p, p + n, compare);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", p[i].x, p[i].y);
}