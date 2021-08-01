#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, wcnt = 0, bcnt = 0;
		string str1, str2;
		cin >> n >> str1 >> str2;
		for (int i = 0; i < n; i++) {
			if (str1[i] != str2[i]) {
				if (str1[i] == 'B')
					bcnt++;
				else
					wcnt++;
			}
		}
		cout << (bcnt > wcnt ? bcnt : wcnt) << "\n";
	}
}