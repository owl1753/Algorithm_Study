#include <iostream>
#include <algorithm>
using namespace std;

int dist[100001];
int n, k;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i <= 100000; i++) {
		if (i <= n) dist[i] = n - i;
		else dist[i] = 987654321;
	}
	for (int i = 1; i <= 100000; i++) {
		dist[i] = min(dist[i], dist[i - 1] + 1);
		if (i < 100000) dist[i] = min(dist[i], dist[i + 1] + 1);
		if (i % 2 == 0) dist[i] = min(dist[i], dist[i / 2]);
		for (int j = i; j <= 100000; j *= 2) {
			dist[j] = min(dist[j], dist[i]);
		}
	}
	cout << dist[k];
}