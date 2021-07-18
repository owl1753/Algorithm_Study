#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int x, y, w, h, wl, hl;
	scanf("%d%d%d%d", &x, &y, &w, &h);
	wl = w - x > x ? x : w - x;
	hl = h - y > y ? y : h - y;
	printf("%d", wl > hl ? hl : wl);
}