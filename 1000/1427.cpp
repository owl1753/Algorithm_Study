#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char a, char b) { return a > b; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	sort(str.begin(), str.end(), cmp);
	cout << str;
}