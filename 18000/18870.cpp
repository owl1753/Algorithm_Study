#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;

vector<int> v;
int x[MAX];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
		v.push_back(x[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < n; i++)
		printf("%d ", lower_bound(v.begin(), v.end(), x[i]) - v.begin());
}