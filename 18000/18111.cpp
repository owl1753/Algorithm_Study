#include <iostream>
#include <string>
using namespace std;

int map[501][501];
int n, m, b, minn = 987654321, answer;

int main() {
	scanf("%d%d%d", &n, &m, &b);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	for (int a = 0; a <= 256; a++) {
		int time = 0, pb = b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > a) {
					time += (2 * (map[i][j] - a));
					pb += (map[i][j] - a);
				}
				else if (map[i][j] < a) {
					time += (a - map[i][j]);
					pb -= (a - map[i][j]);
				}
			}
		}
		if (pb >= 0) {
			if (time <= minn) {
				minn = time;
				answer = a;
			}
		}
	}
	printf("%d %d", minn, answer);
}