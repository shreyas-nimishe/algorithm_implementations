#include<bits/stdc++.h>
using namespace std;
#define LIM 1001

bool isvisited[LIM];
std::vector<int> adj[LIM];

void bfs(int start) {
	// BFS can also measure distance in unweighted graphs i.e no of edges between starting vertex and any other vertex
	isvisited[start] = true;
	int cur, i, next;
	queue<int> q;
	q.push(start);

	while(!q.empty()) {
		cur = q.front();
		q.pop();

		printf("%d ",cur);
		for(i = 0 ; i < adj[cur].size() ; i++) {
			next = adj[cur][i];

			if(!isvisited[next]) {
				isvisited[next] = true;
				q.push(next);
			}
		}
	}
	printf("\n");
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
	printf("BFS Iterative => ");
	bfs(0);
	
	return 0;
}