#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> v1;
vector<char> v2;
stack<int> s;

int main()
{
	int n, flag = 1, index = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		v1.push_back(k);
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag == 0)
			break;
		if (i < v1[index])
		{
			s.push(i);
			v2.push_back('+');
		}
		else
		{
			s.push(i);
			v2.push_back('+');
			while (1)
			{
				if (s.empty())
					break;
				if (v1[index] == s.top())
				{
					s.pop();
					v2.push_back('-');
				}
				else
				{
					if (v1[index] > s.top())
					{
						break;
					}
					else
					{
						flag = 0;
						break;
					}
				}
				index++;
			}
		}
	}
	if (flag == 0)
		printf("NO");
	else
	{
		for (int i = 0; i < v2.size(); i++)
		{
			printf("%c\n", v2[i]);
		}
	}
}