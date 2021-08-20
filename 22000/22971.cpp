#include <iostream>
using namespace std;
#define MOD 998244353

int dp[5001];
int arr[5001];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            if (arr[i] > arr[j])
                dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
}