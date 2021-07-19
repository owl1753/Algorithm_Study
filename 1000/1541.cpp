#include <iostream>
using namespace std;

char str[51];
int answer = 0, tmp = 0, state = 0;

int main() {
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			tmp *= 10;
			tmp += (str[i] - '0');
		}
		else {
			if (state == 0)
				answer += tmp;
			else
				answer -= tmp;
			tmp = 0;
		}
		if (str[i] == '-') {
			state = 1;
		}
	}
	if (state == 0)
		answer += tmp;
	else
		answer -= tmp;
	printf("%d", answer);
}