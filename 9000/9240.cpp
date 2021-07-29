#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 80001
#define ll long long
#define pii pair<ll, ll>

vector<pii> s;
vector<pii> v;
ll c;
double result;

ll ccw(pii p1, pii p2, pii p3) {
	ll temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	temp = temp - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;
	if (temp > 0) {
		return 1;
	}
	else if (temp < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

ll dst(pii p1, pii p2)
{
	return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

bool compare(pii p1, pii p2)
{
	if (ccw(v[0], p1, p2) != 0)
		return ccw(v[0], p1, p2) > 0;
	return dst(v[0], p1) < dst(v[0], p2);
}

void GetConvexHull()
{
	swap(v[0], *min_element(v.begin(), v.end()));
	sort(v.begin() + 1, v.end(), compare);
	s.push_back(v[0]);
	s.push_back(v[1]);
	for (ll i = 2; i < c; i++)
	{
		while (s.size() >= 2 && ccw(s[s.size() - 2], s.back(), v[i]) <= 0)
		{
			s.pop_back();
		}
		s.push_back(v[i]);
	}
}

int main()
{
	scanf("%lld", &c);
	for (ll i = 1; i <= c; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		v.push_back(make_pair(x, y));
	}
	GetConvexHull();
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			result = max(result, (double)sqrt((s[j].second - s[i].second) * (s[j].second - s[i].second) + (s[j].first - s[i].first) * (s[j].first - s[i].first)));
		}
	}
	printf("%lf", result);
}