#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main() {
	int a, b, c, d, result1, result2;
	scanf("%d%d", &a, &b);
	scanf("%d%d", &c, &d);
	result1 = (a * d) + (b * c);
	result2 = b * d;
	printf("%d %d", result1 / gcd(result1, result2), result2 / gcd(result1, result2));
}