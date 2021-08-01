#include <iostream>
using namespace std;
#define ll long long

int arr[100001];
ll n, sum = 0, answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < n; i++) {
		answer += (arr[i] * (sum - arr[i]));
		sum -= arr[i];
	}
	cout << answer;
}