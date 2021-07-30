#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

stack<int> s;

int main()
{
	int K, result = 0;
	scanf("%d", &K);
	while (K--)
	{
		int t;
		scanf("%d", &t);
		if (t == 0)
			s.pop();
		else
			s.push(t);
	}
	while (s.size() != NULL)
	{
		result += s.top();
		s.pop();
	}
	printf("%d", result);
}