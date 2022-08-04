#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int grid[51][51];
int r, c, t, result = 0;
pii defaultPos1, defaultPos2;

int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> grid[i][j];

	for (int i = 0; i < r; i++) {
		if (grid[i][0] == -1) {
			defaultPos1 = make_pair(i, 0);
			defaultPos2 = make_pair(i + 1, 0);
			break;
		}	
	}
			
	while (t--) {
		int plus[51][51];

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				plus[i][j] = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int tmp = grid[i][j] / 5;

				if (tmp == 0) continue;

				if (i > 0 && grid[i - 1][j] != -1) {
					plus[i][j] -= tmp;
					plus[i - 1][j] += tmp;
				}
				if (i + 1 < r && grid[i + 1][j] != -1) {
					plus[i][j] -= tmp;
					plus[i + 1][j] += tmp;
				}
				if (j > 0 && grid[i][j - 1] != -1) {
					plus[i][j] -= tmp;
					plus[i][j - 1] += tmp;
				}
				if (j + 1 < c && grid[i][j + 1] != -1) {
					plus[i][j] -= tmp;
					plus[i][j + 1] += tmp;
				}
			}
		}

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				grid[i][j] += plus[i][j];

		int tmp1 = 0, tmp2 = 0;
		pii pos1, pos2;
		pos1 = defaultPos1;
		pos2 = defaultPos2;

		pos1.second++;

		while (pos1.second < c) {
			swap(tmp1, grid[pos1.first][pos1.second]);
			pos1.second++;
		}

		pos1.second--;
		pos1.first--;

		while (pos1.first >= 0) {
			swap(tmp1, grid[pos1.first][pos1.second]);
			pos1.first--;
		}

		pos1.first++;
		pos1.second--;

		while (pos1.second >= 0) {
			swap(tmp1, grid[pos1.first][pos1.second]);
			pos1.second--;
		}

		pos1.second++;
		pos1.first++;

		while (pos1.first < defaultPos1.first) {
			swap(tmp1, grid[pos1.first][pos1.second]);
			pos1.first++;
		}

		pos2.second++;

		while (pos2.second < c) {
			swap(tmp2, grid[pos2.first][pos2.second]);
			pos2.second++;
		}

		pos2.second--;
		pos2.first++;

		while (pos2.first < r) {
			swap(tmp2, grid[pos2.first][pos2.second]);
			pos2.first++;
		}

		pos2.first--;
		pos2.second--;

		while (pos2.second >= 0) {
			swap(tmp2, grid[pos2.first][pos2.second]);
			pos2.second--;
		}

		pos2.second++;
		pos2.first--;

		while (pos2.first > defaultPos2.first) {
			swap(tmp2, grid[pos2.first][pos2.second]);
			pos2.first--;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] >= 0) result += grid[i][j];
		}
	}
		
	cout << result;
}