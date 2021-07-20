#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
#define MAX 100001

vector<pair<int, int>> edge[MAX];

vector<int> dijkstra(int start, int N)
{
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));

    vector<int> dist(N, INT_MAX);
    dist[start] = 0;

    while (q.size() != 0)
    {
        int cost = -q.top().first;                       // ���� ���� �Ÿ�
        int here = q.top().second;                       // ���� ����
        q.pop();
        if (dist[here] < cost)
            continue;
        for (int i = 0; i < edge[here].size(); i++)
        {
            int there = edge[here][i].first;
            int distance = edge[here][i].second + cost;
            if (dist[there] > distance)
            {
                dist[there] = distance;
                q.push(make_pair(-distance, there));
            }
        }
    }
    return dist;
}

int main()
{
    int N, M, start, end;
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;                               // ���� ����, ���� ����, ����ġ
        edge[a].push_back(make_pair(b, c));
    }
    cin >> start >> end;
    vector<int> dist = dijkstra(start, N + 1);
    cout << dist[end];
}