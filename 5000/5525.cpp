#include <iostream>
using namespace std;

int main() {
	char str[1000001];
	int n, m, cnt = 0, len = 0;
	scanf("%d", &m);
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < n; i++) {
		if (str[i] == 'O') {
			if (str[i - 1] == 'I' && str[i + 1] == 'I')
				len++;
			else
				len = 0;
			if (len >= m)
				cnt++;
		}
		else if (str[i] == 'I' && str[i - 1] == 'I')
			len = 0;
		
	}
	printf("%d", cnt);
}