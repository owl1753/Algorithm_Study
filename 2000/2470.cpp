#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 100001
#define INF 1000000001

int arr[MAX];
int n, result1 = INF, result2 = INF;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++) {
		int left = i + 1, right = n, mid, t = MAX + 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (abs(result1 + result2) > abs(arr[i] + arr[mid])) {
				result1 = arr[i];
				result2 = arr[mid];
			}
			if (0 >= arr[i] + arr[mid]) {
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
	}
	if (result1 > result2)
		swap(result1, result2);
	printf("%d %d", result1, result2);
}