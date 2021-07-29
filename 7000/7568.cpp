#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> v;
	int ranking[50] = { 0 }, n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				ranking[i]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ranking[i] + 1 << " ";
	}
}