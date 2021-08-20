#include <iostream>
#include <string>
using namespace std;
#define INF 987654321

pair<string, int> result;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	result.second = INF;
	while (n--) {
		pair<string, int> temp;
		cin >> temp.first >> temp.second;
		if (temp.second < result.second)
			result = temp;
	}
	cout << result.first;
}