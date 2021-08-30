#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int arr[51];
int brr[51];
int n, result = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		cin >> brr[i];
	sort(arr, arr + n);
	sort(brr, brr + n, cmp);
	for (int i = 0; i < n; i++)
		result += arr[i] * brr[i];
	cout << result;
}