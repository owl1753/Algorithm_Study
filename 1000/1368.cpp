#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 310

struct Adj
{
    int u, v, w;
};

vector<Adj> v;
int par[MAX];
int N, cost = 0;

int find(int n)
{
    if (par[n] == -1)
        return n;
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

bool compare(Adj a, Adj b) { return a.w < b.w; }

int main()
{
    memset(par, -1, sizeof(par));
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        Adj temp;
        temp.u = i;
        temp.v = N + 1;
        cin >> temp.w;
        v.push_back(temp);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            Adj temp;
            temp.u = i;
            temp.v = j;
            cin >> temp.w;
            v.push_back(temp);
        }
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
    {
        if (find(v[i].u) == find(v[i].v))
            continue;
        merge(v[i].u, v[i].v);
        cost += v[i].w;
    }
    cout << cost;
}
