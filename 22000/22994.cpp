#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char image[1001][1001];
int ni, mj, n, m, i, j;
vector<int> iposs;
vector<int> jposs;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> ni >> mj;
	for (int k = 0; k < ni; k++)
		for (int l = 0; l < mj; l++)
			cin >> image[k][l];
	for (int k = max(ni, mj); k >= 1; k--) {
		if (ni % k == 0)
			iposs.push_back(k);
		if (mj % k == 0)
			jposs.push_back(k);
	}
	for (int k = 0; k < iposs.size(); k++) {
		int flag = 1;
		for (int l = 0; l < mj; l++) {
			int cnt = 0;
			int index = 1;
			char temp = image[0][l];
			while (index < ni) {
				cnt++;
				if (cnt == iposs[k]) {
					cnt = 0;
					temp = image[index][l];
				}
				else {
					if (temp != image[index][l]) {
						flag = 0;
						break;
					}
				}
				index++;
			}
			if (flag == 0)
				break;
		}
		if (flag == 1) {
			i = iposs[k];
			n = ni / i;
			break;
		}
	}
	for (int k = 0; k < jposs.size(); k++) {
		int flag = 1;
		for (int l = 0; l < ni; l++) {
			int cnt = 0;
			int index = 1;
			char temp = image[l][0];
			while (index < mj) {
				cnt++;
				if (cnt == jposs[k]) {
					cnt = 0;
					temp = image[l][index];
				}
				else {
					if (temp != image[l][index]) {
						flag = 0;
						break;
					}
				}
				index++;
			}
			if (flag == 0)
				break;
		}
		if (flag == 1) {
			j = jposs[k];
			m = mj / j;
			break;
		}
	}
	cout << n << " " << m << "\n";
	for (int k = 0; k < ni; k+=i) {
		for (int l = 0; l < mj; l+=j) {
			cout << image[k][l];
		}
		cout << "\n";
	}
		
}