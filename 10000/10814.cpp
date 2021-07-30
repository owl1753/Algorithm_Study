#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 100001

struct member
{
	int age, order;
	string name;
};

bool compare(member a, member b)
{
	if (a.age == b.age)
		return a.order < b.order;
	return a.age < b.age;
}

member arr[MAX];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].age >> arr[i].name;
		arr[i].order = i;
	}
	sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].age << " " << arr[i].name << "\n";
	}
}