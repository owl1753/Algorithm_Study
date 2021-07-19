#include <iostream>
#include <vector>
using namespace std;
#define MAX 101
#define ll long long

struct My {
	int a, b, c, d;
};

vector<My> v;
ll dp[MAX][MAX];
int map[MAX][MAX];
int n, m, k;

int main() {

	scanf("%d%d", &n, &m);
	scanf("%d", &k);
	while (k--) {
		My tmp;
		scanf("%d%d%d%d", &tmp.a, &tmp.b, &tmp.c, &tmp.d);
		v.push_back(tmp);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		int flag = 1;
		for (int j = 0; j < v.size(); j++) {
			if ((v[j].b == i && v[j].a == 0 && v[j].d == i - 1 && v[j].c == 0) || (v[j].b == i - 1 && v[j].a == 0 && v[j].d == i && v[j].c == 0))
				flag = 0;
		}
		if (flag == 1)
			dp[i][0] += dp[i - 1][0];
	}
	for (int i = 1; i <= n; i++) {
		int flag = 1;
		for (int j = 0; j < v.size(); j++) {
			if ((v[j].b == 0 && v[j].a == i && v[j].d == 0 && v[j].c == i - 1) || (v[j].b == 0 && v[j].a == i - 1 && v[j].d == 0 && v[j].c == i))
				flag = 0;
		}
		if (flag == 1)
			dp[0][i] += dp[0][i - 1];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int flag1 = 1, flag2 = 1;
			for (int k = 0; k < v.size(); k++) {
				if ((v[k].b == i && v[k].a == j && v[k].d == i - 1 && v[k].c == j) || (v[k].b == i - 1 && v[k].a == j && v[k].d == i && v[k].c == j))
					flag1 = 0;
				if ((v[k].b == i && v[k].a == j && v[k].d == i && v[k].c == j - 1) || (v[k].b == i && v[k].a == j - 1 && v[k].d == i && v[k].c == j))
					flag2 = 0;
			}
			if (flag1 == 1)
				dp[i][j] += dp[i - 1][j];
			if (flag2 == 1)
				dp[i][j] += dp[i][j - 1];
		}
	}
	printf("%lld", dp[m][n]);
}