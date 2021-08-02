#include <iostream>
using namespace std;
#define MAX 1000010

char str[MAX];
char s[MAX];
int top = 0;

int main() {
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++) {
		s[top] = str[i];
		if (top >= 3) {
			if (s[top - 3] == 'P' && s[top - 2] == 'P' && s[top - 1] == 'A' && s[top] == 'P') {
				top -= 3;
			}
		}
		top++;
	}
	if (top == 1 && s[top - 1] == 'P')
		printf("PPAP\n");
	else
		printf("NP\n");
}