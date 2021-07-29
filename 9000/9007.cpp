#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;
#define MAX 1001

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<int> v1;
		vector<int> v2;
		vector<int> v3;
		int c[5][MAX];
		int k, n, left, right, mid, result1 = INT_MAX, result2 = INT_MAX;
		scanf("%d%d", &k, &n);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &c[i][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				v1.push_back(c[1][i] + c[2][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				v2.push_back(c[3][i] + c[4][j]);
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		for (int i = 0; i < v1.size(); i++) {
			int t1 = INT_MAX, t2 = INT_MAX;
			left = 0; right = v2.size() - 1;
			while (left <= right) {
				mid = (left + right) / 2;
				if (k >= v1[i] + v2[mid])
				{
					left = mid + 1;
					t1 = v1[i] + v2[mid];
				}
				else
					right = mid - 1;
			}
			left = 0; right = v2.size() - 1;
			while (left <= right) {
				mid = (left + right) / 2;
				if (k <= v1[i] + v2[mid])
				{
					right = mid - 1;
					t2 = v1[i] + v2[mid];
				}
				else
					left = mid + 1;
			}
			if (abs(k - t1) == abs(k - t2))
				v3.push_back(t1);
			else if (abs(k - t1) > abs(k - t2))
				v3.push_back(t2);
			else
				v3.push_back(t1);
		}
		sort(v3.begin(), v3.end());
		left = 0; right = v3.size() - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (k >= v3[mid])
			{
				left = mid + 1;
				result1 = v3[mid];
			}
			else
				right = mid - 1;
		}
		left = 0; right = v3.size() - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (k <= v3[mid])
			{
				right = mid - 1;
				result2 = v3[mid];
			}
			else
				left = mid + 1;
		}
		if (abs(k - result1) == abs(k - result2))
			printf("%d\n", result1);
		else if (abs(k - result1) > abs(k - result2))
			printf("%d\n", result2);
		else
			printf("%d\n", result1);
	}
}