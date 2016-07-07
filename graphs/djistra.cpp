#include<bits/stdc++.h>
using namespace std;
#define MAX_NODES 1000

typedef pair< int, int> pii;
int min_dist[MAX_NODES], i, src;

std::vector< pii > adj[MAX_NODES];

int main() {
	int vertices, edges;
	int v1, v2, weight, i, next;
	cin >> vertices >> edges;

	for(i = 0 ; i < edges; i++) {
		cin >> v1 >> v2 >> weight;
		adj[v1].push_back(make_pair(v2, weight));
	}

	for(i = 1; i <= vertices ; i++) {
		min_dist[i] = 1e6; 		// initialize distance to infinity or a very high value
	}

	cin >> src ;
	min_dist[src] = 0;
	
	priority_queue<pii, vector< pii >, greater< pii > > pq;

	pq.push(make_pair(min_dist[src], src));

	while(!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();

		for(int i = 0 ; i < adj[cur].size() ; i++) {
			int next = adj[cur][i].first;

			if(min_dist[next] > min_dist[cur] + adj[cur][i].second) {
				min_dist[next] = min_dist[cur] + adj[cur][i].second;
				pq.push(make_pair(min_dist[next], next));
			}

		}
	}

	printf("Minimum distance of each node from source node %d\n",src );
	for(int i = 1 ; i <= vertices ; i++) {
		printf("Node = %d distance = %d\n",i, min_dist[i]);
	}
	return 0;
}