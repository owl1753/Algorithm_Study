#include <iostream>
#include <algorithm>
using namespace std;

struct con
{
	int start, end;
};

bool compare(con a, con b)
{
	if (a.end == b.end)
		return a.start < b.start;
	else
		return a.end < b.end;
}

int main()
{
	con arr[100001];
	int n, time = 0, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].start >> arr[i].end;
	}
	sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++)
	{
		if (time <= arr[i].start)
		{
			time = arr[i].end;
			cnt++;
		}
	}
	cout << cnt;
}