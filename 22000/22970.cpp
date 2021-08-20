#include <iostream>
#include <algorithm>
using namespace std;

int arr[5001];
int n, l, r, result = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    l = 1;
    r = n;
    while (1) {
        int cond = 0, cnt = 1;
        if (l == r)
            break;
        for (int i = l + 1; i <= r; i++) {
            if (arr[i - 1] < arr[i] && cond == 1) {
                l = i - 1;
                break;
            }
            else if (arr[i - 1] > arr[i] && cond == 0)
                cond = 1;
            else if (arr[i - 1] == arr[i]) {
                l = i;
                break;
            }
            cnt++;
            if (i == r) {
                l = r;
                break;
            }
        }
        result = max(result, cnt);
    }
    if (n == 1)
        cout << 1;
    else
        cout << result;
}