#include <iostream>
#include <string>
using namespace std;

string s[51];
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < s[0].length(); i++){
		int flag = 1;
		char temp = s[0][i];
		for (int j = 1; j < n; j++){
			if (temp != s[j][i]){
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			cout << temp;
		else
			cout << "?";
	}
}