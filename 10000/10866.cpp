#include <iostream>
#include <string>
using namespace std;

int deque[21000];
int n, front = 10000, back = 10001;
string ch;

int main() {
	cin >> n;
	while (n--) {
		cin >> ch;
		if (ch == "push_front") {
			int x;
			cin >> x;
			deque[front] = x;
			front--;
		}
		else if (ch == "push_back") {
			int x;
			cin >> x;
			deque[back] = x;
			back++;
		}
		else if (ch == "pop_front") {
			if (back - front == 1)
				cout << "-1\n";
			else {
				cout << deque[front + 1] << "\n";
				front++;
			}
		}
		else if (ch == "pop_back") {
			if (back - front == 1)
				cout << "-1\n";
			else {
				cout << deque[back - 1] << "\n";
				back--;
			}	
		}
		else if (ch == "size") {
			cout << (back - front - 1) << "\n";
		}
		else if (ch == "empty") {
			if (back - front == 1)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (ch == "front") {
			if (back - front == 1)
				cout << "-1\n";
			else
				cout << deque[front + 1] << "\n";
		}
		else if (ch == "back") {
			if (back - front == 1)
				cout << "-1\n";
			else
				cout << deque[back - 1] << "\n";
		}
	}
}