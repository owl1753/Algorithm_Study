#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define INF 9876544321


int arr[21][21];
int check[21];
int result = INF;
int n;

void func(int k, int sel) {
	if (k == 0) {
		vector<int> startteam, linkteam;
		int start = 0, link = 0;

		for (int i = 1; i <= n; i++)
			if (check[i])
				startteam.push_back(i);
			else
				linkteam.push_back(i);

		for (int i = 0; i < n / 2; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				start += (arr[startteam[i]][startteam[j]] + arr[startteam[j]][startteam[i]]);
				link += (arr[linkteam[i]][linkteam[j]] + arr[linkteam[j]][linkteam[i]]);
			}
		}

		if (abs(start - link) < result)
			result = abs(start - link);

		return;
	}
	for (int i = sel + 1; i <= n; i++) {
		if (check[i])
			continue;
		check[i] = 1;
		func(k - 1, i);
		check[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	func(n / 2, 0);
	cout << result;
}