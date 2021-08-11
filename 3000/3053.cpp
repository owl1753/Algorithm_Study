#include <iostream>
using namespace std;
#define PI 3.14159265358979

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int r;
	cin >> r;
	cout << fixed;
	cout.precision(6);
	cout << r * r * PI << "\n";
	cout << 2.0 * (double)r * (double)r << "\n";
}