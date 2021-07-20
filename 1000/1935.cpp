#pragma warining(disable:4996)
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	stack<double> s;
	char ex[101];
	int alpha[26];
	int n;
	scanf("%d", &n);
	scanf("%s", ex);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &alpha[i]);
	}
	for (int i = 0; ex[i] != '\0'; i++)
	{
		double a, b;
		if (ex[i] == '+')
		{
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			s.push((double)b + (double)a);
		}
		else if (ex[i] == '-')
		{
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			s.push((double)b - (double)a);
		}
		else if (ex[i] == '*')
		{
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			s.push((double)b * (double)a);
		}
		else if (ex[i] == '/')
		{
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			s.push((double)b / (double)a);
		}
		else
		{
			s.push((double)(alpha[ex[i] - 65]));
		}
	}
	printf("%.2lf", s.top());
}