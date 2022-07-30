#include <iostream>
#include <set>
using namespace std;

int positions[1000001];
int fuels[1000001];
int n, s, l, r, lFuel = 0, rFuel = 0;
bool invalid_l = false, invalid_r = false;
set<int> result;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> positions[i];
	for (int i = 1; i <= n; i++) cin >> fuels[i];
	l = r = s;

	while (true) {
		if (!invalid_l) result.insert(l);
		if (!invalid_r) result.insert(r);

		if (1 <= l && l <= n && 1 <= r && r <= n) {
			int distance = positions[r] - positions[l];

			if (!invalid_l ) {
				if (lFuel < fuels[l]) lFuel = fuels[l];
				if (rFuel < fuels[l] - distance) rFuel = fuels[l] - distance;
			}
			if (!invalid_r) {
				if (rFuel < fuels[r]) rFuel = fuels[r];
				if (lFuel < fuels[r] - distance) lFuel = fuels[r] - distance;
			}
			
		}

		if (l > 1) {
			int cost = positions[l] - positions[l - 1];
			if (lFuel - cost >= 0 && lFuel != 0) {
				lFuel -= cost;
				l--;
				invalid_l = false;
			}
			else invalid_l = true;
		}
		else invalid_l = true;
			 
		if (r < n) {
			int cost = positions[r + 1] - positions[r];
			if (rFuel - cost >= 0 && rFuel != 0) {
				rFuel -= cost;
				r++;
				invalid_r = false;
			}
			else invalid_r = true;
		}
		else invalid_r = true;

		if (invalid_l && invalid_r) break;
	}

	for (set<int>::iterator iter = result.begin(); iter != result.end(); iter++) cout << *iter << " ";
}