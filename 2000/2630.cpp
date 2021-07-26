#include <iostream>
using namespace std;

int paper[129][129];
int wcnt = 0, bcnt = 0;

void func(int x, int y, int r, int c, int n) {
	int hcolor = paper[x][y];
	int flag = 1;
	for (int i = x; i <= r; i++) {
		if (flag == 0)
			break;
		for (int j = y; j <= c; j++) {
			if (paper[i][j] != hcolor) {
				flag = 0;
				break;
			}
		}
	}
	if (flag == 1) {
		if (hcolor == 0)
			wcnt++;
		else if (hcolor == 1)
			bcnt++;
	}
	else if (flag == 0) {
		func(x, y, r - (n / 2), c - (n / 2), n / 2);
		func(x, y + (n / 2), r - (n / 2), c, n / 2);
		func(x + (n / 2), y, r, c - (n / 2), n / 2);
		func(x + (n / 2), y + (n / 2), r, c, n / 2);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &paper[i][j]);
	func(1, 1, n, n, n);
	printf("%d\n%d", wcnt, bcnt);

}