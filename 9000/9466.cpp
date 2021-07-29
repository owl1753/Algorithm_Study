#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
int student[MAX];
int visited[MAX];
int finished[MAX];
int answer, cycle = 0;

void dfs(int here)
{
	visited[here] = 1;
	int next = student[here];
	if (visited[next] == 0)
		dfs(next);
	if (here == next)
		answer--;
	else if (finished[next] == 0)
	{
		cycle = next;
		answer--;
	}
	else if (cycle != 0)
	{
		answer--;
	}
	if (cycle == here)
	{
		cycle = 0;
	}
	finished[here] = 1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		answer = n;
		cycle = 0;
		for (int i = 1; i <= n; i++)
			visited[i] = 0;
		for (int i = 1; i <= n; i++)
			finished[i] = 0;
		for (int i = 1; i <= n; i++)
			cin >> student[i];
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0)
				dfs(i);
			cycle = 0;
		}
		cout << answer << "\n";
	}
}