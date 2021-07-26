#include <iostream>
using namespace std;
#define MAX 101

int arr[MAX];
int result = 0;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] + arr[j] + arr[k] <= m && (m - (arr[i] + arr[j] + arr[k]) < m - result))
					result = arr[i] + arr[j] + arr[k];
			}
		}
	}
	printf("%d", result);
}