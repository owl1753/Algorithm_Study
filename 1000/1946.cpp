#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

struct Emp {
	int first, second;
};

bool compare(Emp a, Emp b) {
	return a.first < b.first;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		Emp s[MAX];
		int n, cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &s[i].first, &s[i].second);
		sort(s, s + n, compare);
		cnt++;
		for (int i = 1; i < n; i++) {
			if (s[i - 1].second < s[i].second) {
				int t = s[i - 1].second;
				s[i - 1].second = s[i].second;
				s[i].second = t;
			}
			else
				cnt++;
		}
		printf("%d\n", cnt);
	}
}