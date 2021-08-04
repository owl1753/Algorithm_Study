#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

struct Customer 
{
	ll id, w, desk;
};

bool compare(Customer a, Customer b)
{
	if (a.w == b.w)
		return a.desk > b.desk;
	else
		return a.w < b.w;
}

priority_queue<pair<int, int>> pq;
vector<Customer> v;

int main()
{
	ll N, k, result = 0;
	scanf("%lld%lld", &N, &k);
	for (ll i = 0; i < N; i++)
	{
		Customer temp;
		scanf("%lld%lld", &temp.id, &temp.w);
		temp.desk = 0;
		v.push_back(temp);
	}
	for (ll i = 0; i < N; i++)
	{
		if (i < k)
		{
			v[i].desk = i + 1;
			pq.push(make_pair(-v[i].w, -v[i].desk));
		}
		else
		{
			v[i].desk = -pq.top().second;
			v[i].w += -pq.top().first;
			pq.pop();
			pq.push(make_pair(-v[i].w, -v[i].desk));
		}
	}
	sort(v.begin(), v.end(), compare);
	for (ll i = 0; i < N; i++)
		result += ((i + 1) * v[i].id);
	printf("%lld", result);
}