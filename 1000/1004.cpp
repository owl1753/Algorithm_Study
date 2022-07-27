#include <iostream>
using namespace std;

struct Vector2 {
	int x;
	int y;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		Vector2 startPos;
		Vector2 endPos;
		int n, result = 0;
		
		cin >> startPos.x >> startPos.y >> endPos.x >> endPos.y;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int x;
			int y;
			int r;
			cin >> x >> y >> r;

			int startDistance = (startPos.x - x) * (startPos.x - x) + (startPos.y - y) * (startPos.y - y);
			int endDistance = (endPos.x - x) * (endPos.x - x) + (endPos.y - y) * (endPos.y - y);

			if (startDistance > r * r && endDistance < r * r) result++;
			if (startDistance < r * r && endDistance > r * r) result++;
		}

		cout << result << "\n";
	}
}