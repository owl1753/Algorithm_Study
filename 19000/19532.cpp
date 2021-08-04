#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f, flag = 0;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	for (int i = -999; i <= 999 && flag == 0; i++) {
		for (int j = -999; j <= 999; j++) {
			if (a*i + b*j == c && d*i + e*j == f){
				printf("%d %d", i, j);
				flag = 1;
				break;
			}
		}
	}
}