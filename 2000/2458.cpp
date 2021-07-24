#include <iostream>
#include <vector>
using namespace std;
#define MAX 501

vector<int> adj1[MAX];
vector<int> adj2[MAX];
int visited1[MAX] = { 0 };
int visited2[MAX] = { 0 };
int dcnt = 0;

void dfs1(int start)
{
	if (visited1[start] == 1)
		return;
	dcnt++;
	visited1[start] = 1;
	for (int i = 0; i < adj1[start].size(); i++)
	{
		int there = adj1[start][i];
		if (visited1[there] == 0)
			dfs1(there);
	}
}	
void dfs2(int start)
{
	if (visited2[start] == 1)
		return;
	dcnt++;
	visited2[start] = 1;
	for (int i = 0; i < adj2[start].size(); i++)
	{
		int there = adj2[start][i];
		if (visited2[there] == 0)
			dfs2(there);
	}
}

int main()
{
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj1[a].push_back(b);
		adj2[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		dfs1(i);
		dfs2(i);
		if (dcnt - 1 == n)
			cnt++;
		dcnt = 0;
		for (int j = 1; j <= n; j++)
		{
			visited1[j] = 0;
			visited2[j] = 0;
		}
	}
	cout << cnt;
}