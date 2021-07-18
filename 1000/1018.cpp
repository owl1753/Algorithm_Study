#include <iostream>
#include <string>
using namespace std;

char chess[51][51];
char ex1[8][8] = { {'W','B','W','B','W','B','W','B'},
				 {'B','W','B','W','B','W','B','W'},
				 {'W','B','W','B','W','B','W','B'},
				 {'B','W','B','W','B','W','B','W'},
				 {'W','B','W','B','W','B','W','B'},
				 {'B','W','B','W','B','W','B','W'},
				 {'W','B','W','B','W','B','W','B'},
				 {'B','W','B','W','B','W','B','W'}, };
char ex2[8][8] = { {'B','W','B','W','B','W','B','W'},
				 {'W','B','W','B','W','B','W','B'},
				 {'B','W','B','W','B','W','B','W'},
				 {'W','B','W','B','W','B','W','B'},
				 {'B','W','B','W','B','W','B','W'},
				 {'W','B','W','B','W','B','W','B'},
				 {'B','W','B','W','B','W','B','W'},
				 {'W','B','W','B','W','B','W','B'}, };
int n, m, cnt = 0, minn = 987654321;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &chess[i][j]);
	for (int a = 0; a + 8 <= n; a++) {
		for (int b = 0; b + 8 <= m; b++) {
			for (int i = a; i < a + 8; i++) {
				for (int j = b; j < b + 8; j++) {
					if (chess[i][j] != ex1[i - a][j - b])
						cnt++;
				}
			}
			if (minn > cnt)
				minn = cnt;
			cnt = 0;
			for (int i = a; i < a + 8; i++) {
				for (int j = b; j < b + 8; j++) {
					if (chess[i][j] != ex2[i - a][j - b])
						cnt++;
				}
			}
			if (minn > cnt)
				minn = cnt;
			cnt = 0;
		}
	}
	printf("%d", minn);

}