#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

struct Pos
{
	int x, y;
};

bool compare(Pos a, Pos b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main()
{
	Pos arr[MAX];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &arr[i].x, &arr[i].y);
	}
	sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
}