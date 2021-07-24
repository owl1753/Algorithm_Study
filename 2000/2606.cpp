#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

struct List {
	int number;
	struct List* next;
	struct List* prev;
};
typedef struct List List;

void init(List* start) {
	List* end = (List*)malloc(sizeof(List));
	start->next = end;
	start->prev = end;
	end->next = start;
	end->prev = start;
}

void push(List* start, int t) {
	List* node = (List*)malloc(sizeof(List));
	node->number = t;
	node->next = start->prev;
	node->prev = start->prev->prev;
	start->prev->prev->next = node;
	start->prev->prev = node;
}

void dfs(List* adj[], int cur, int* result, int visited[]) {
	List* p = adj[cur];
	p = p->next;
	while (p->next != adj[cur]) {
		if (visited[p->number] == 0)
		{
			visited[p->number] = 1;
			(*result)++;
			dfs(adj, p->number, result, visited);
		}
		p = p->next;
	}
}

int main() {
	List* adj[MAX];
	int visited[MAX];
	int n, m, result = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		adj[i] = (List*)malloc(sizeof(List));
		init(adj[i]);
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		push(adj[a], b);
		push(adj[b], a);
	}
	visited[1] = 1;
	dfs(adj, 1, &result, visited);
	printf("%d", result);
}