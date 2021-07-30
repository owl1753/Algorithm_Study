#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100001

int par[MAX];
int plane[MAX];
int G, P, cnt = 0;

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

int main()
{
    memset(par, -1, sizeof(par));
    cin >> G;
    cin >> P;
    for (int i = 1; i <= P; i++)
        cin >> plane[i];
    for (int i = 1; i <= P; i++)
    {
        int root = find(plane[i]);
        if (root != 0)
            merge(root, root - 1);
        else
            break;
        cnt++;
    }
    cout << cnt;
}
