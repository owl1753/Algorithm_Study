#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 101

struct adj
{
	int a, b, c;
};

int par[MAX];
int n, result = 0, flag = 1;
vector<adj> v;

int find(int n)
{
	if (par[n] == -1) return n;
	return par[n] = find(par[n]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	par[a] = b;
}

bool compare(adj a, adj b)
{
	return a.c < b.c;
}

int main()
{
	memset(par, -1, sizeof(par));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			adj tmp;
			char ch;
			scanf(" %c", &ch);
			if (ch == '0')
				continue;
			tmp.a = i; tmp.b = j;
			if ('a' <= ch && ch <= 'z')
				tmp.c = ch - 'a' + 1;
			if ('A' <= ch && ch <= 'Z')
				tmp.c = ch - 'A' + 27;
			v.push_back(tmp);
		}
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
	{
		if (find(v[i].a) == find(v[i].b)) {
			result += v[i].c;
			continue;
		}
		merge(v[i].a, v[i].b);
	}
	for (int i = 1; i < n; i++) {
		if (find(i) != find(i - 1)) {
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		printf("%d", result);
	else
		printf("-1");
}