#include <iostream>
using namespace std;

int main() {
	int arr[100001];
	int n, s, sum, start = 0, end = 0, minn = 987654321;
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sum = arr[0];
	while (start <= end && end < n) {
		if (sum >= s) {
			if (minn > (end - start + 1))
				minn = end - start + 1;
			sum -= arr[start];
			start++;
		}
		else {
			end++;
			sum += arr[end];
		}
	}
	if (minn == 987654321)
		printf("0");
	else
		printf("%d", minn);
}