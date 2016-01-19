#include<bits/stdc++.h>
using namespace std;
#define LIM 1001

bool isvisited[LIM];
std::vector<int> adj[LIM];
void dfs_iterative(int start) {
	int cur, i, next;
	isvisited[start] = true;
	stack<int> s;
	s.push(start);
	while(!s.empty()) {
		cur = s.top();
		s.pop();

		printf("%d ",cur );
		for(i = 0; i < adj[cur].size() ; i++) {
			next = adj[cur][i];

			if(!isvisited[next]) {
				isvisited[next] = true;
				s.push(next);
			}
		}
	}
	printf("\n");
}

void dfs_recursive(int cur) {
	printf("%d ",cur);
	for(int i = 0 ; i < adj[cur].size() ; i++ ) {
		int next = adj[cur][i];
		if(!isvisited[next]) {
			isvisited[next] = true;
			dfs_recursive(next);
		}
	}
}

int main() {
	int nodes, edges, v1, v2, i;
	printf("This Program traverses the graph using dfs in directed graph\nEnter no of edges and vertices: ");
	scanf("%d%d",&edges, &nodes);

	for(i = 0 ; i < edges ; i++) {
		scanf("%d%d",&v1,&v2);
		adj[v1].push_back(v2);
	}

	printf("Traversing the Graph...\n");
	printf("DFS Iterative => ");
	dfs_iterative(0);
	memset(isvisited, 0, sizeof(isvisited));
	printf("DFS Recursive => ");
	dfs_recursive(0);
	printf("\n");
	return 0;
}