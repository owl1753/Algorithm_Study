#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int check[8001];
int n, maxx = 0, minn = 0, mid = 0, most = 0, sum = 0, mcheck = 1, cnt = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	maxx = arr[0];
	minn = arr[0];
	for (int i = 0; i < n; i++) {
		maxx = max(maxx, arr[i]);
		minn = min(minn, arr[i]);
		check[arr[i] + 4000]++;
		sum += arr[i];
		if ((n / 2) == i)
			mid = arr[i];
	}
	for (int i = 0; i <= 8000; i++) {
		if (mcheck < check[i]) {
			mcheck = check[i];
		}
	}
	for (int i = 0; i <= 8000; i++) {
		if (check[i] == mcheck) {
			most = i - 4000;
			if (cnt == 1)
				break;
			cnt++;
		}
	}
	printf("%.lf\n", sum / (double)n);
	printf("%d\n", mid);
	printf("%d\n", most);
	printf("%d\n", maxx - minn);
}