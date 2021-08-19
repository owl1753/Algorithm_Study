#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, m, result = 0;

bool CheckVaild(pair<int, int> a) {
	return 0 < a.first && 0 < a.second && a.first <= n && a.second <= m;
}

int func(pair<int, int> here, pair<int, int> prev, int k) {
	if (k == 0)
		return arr[here.first][here.second];

	int sum = 0;

	for (int i = 0; i < 4; i++) {
		pair<int, int> next;
		next.first = here.first + dx[i];
		next.second = here.second + dy[i];
		if (CheckVaild(next)) {
			if (prev != next) {
				sum = max(sum, arr[here.first][here.second] + func(next, here, k - 1));
			}
		}
	}

	if (k == 3) {
		for (int i = 0; i < 4; i++) {
			int temp = 0;
			for (int j = 0; j < 4; j++) {
				if (i == j)
					continue;
				pair<int, int> add;
				add.first = here.first + dx[j];
				add.second = here.second + dy[j];
				if (CheckVaild(add)) {
					temp += arr[add.first][add.second];
				}
				else {
					temp = 0;
					break;
				}
			}
			sum = max(sum, temp + arr[here.first][here.second]);
		}
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			result = max(result, func(make_pair(i, j), make_pair(0, 0), 3));
		}
	}
	cout << result;
}