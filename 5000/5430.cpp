#include <iostream>
#include <deque>
using namespace std;

int main() {	
	int t;
	scanf("%d", &t);
	while (t--) {
		char str[300001];
		char str2[300001];
		deque<int> d;
		int n, k = 0, state = -1, error = 0;
		scanf("%s", str);
		scanf("%d", &n);
		scanf("%s", str2);
		for (int i = 0; str2[i] != '\0'; i++) {
			if ('0' <= str2[i] && str2[i] <= '9') {
				k *= 10;
				k += str2[i] - '0';
			}
			else {
				if (k != 0)
					d.push_back(k);
				k = 0;
			}

		}
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == 'R')
				state *= -1;
			else if (str[i] == 'D') {
				if (d.empty()) {
					error = 1;
					break;
				}
				else if (state == -1)
					d.pop_front();
				else
					d.pop_back();
			}
		}
		if (error == 1)
			printf("error\n");
		else {
			if (d.empty()) {
				printf("[");
			}
			else if (state == -1) {
				printf("[%d", d.front());
				d.pop_front();
			}
			else {
				printf("[%d", d.back());
				d.pop_back();
			}
			while (d.size() > 1) {
				int cur;
				if (state == -1) {
					cur = d.front();
					d.pop_front();
				}
				else {
					cur = d.back();
					d.pop_back();
				}
				printf(",%d", cur);
			}
			if (d.empty())
				printf("]\n");
			else {
				printf(",%d]\n", d.front());
				d.pop_front();
			}
		}
	}
}