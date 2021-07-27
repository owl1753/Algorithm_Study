#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;
#define MAX 110

int main()
{
	while (1)
	{
		stack<char> s;
		char str[MAX];
		int flag = 0;
		fgets(str, sizeof(str), stdin);
		if (!strcmp(str, ".\n"))
			break;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '(' || str[i] == '[')
				s.push(str[i]);
			if (str[i] == ')')
			{
				if (s.size() == NULL)\
				{
					flag = 1;
					break;
				}
				if (s.top() == '(')
					s.pop();
				else
				{
					flag = 1;
					break;
				}
			}
			if (str[i] == ']')
			{
				if (s.size() == NULL)\
				{
					flag = 1;
					break;
				}
				if (s.top() == '[')
					s.pop();
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (s.size() == NULL && flag == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
}