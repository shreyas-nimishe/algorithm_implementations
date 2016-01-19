#include<bits/stdc++.h>
using namespace std;

#define LIM 1001
#define INF 99999
int graph[LIM][LIM], min_weight[LIM][LIM], i, j, k, temp;


void floyd_warshall(int n) {
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j++) {
			min_weight[i][j] = graph[i][j] == 0 ? INF : graph[i][j];
		}
		graph[i][i] = 0;
	}

	for(k = 0 ; k < n ; k++ ){
		for(j = 0 ; j < n ; j++) {
			for(i = 0 ; i < n ; i++ ) {
				min_weight[i][j] = min(min_weight[i][j], min_weight[i][k] + min_weight[k][j]);
			}
		}
	}

	//Printing solution
	printf("no  ");
	for(i = 0 ; i < n ; i++){
		printf("%d    ",i);
	}
	printf("\n");
	for(i = 0 ; i < n ; i++) {
		printf("%d  ",i );
		for(j = 0 ; j < n ; j++) {
			printf("%d   ",min_weight[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int nodes, edges, v1, v2, i, wt;
	printf("This Program traverses the graph using dfs in directed graph\nEnter no of edges and vertices: ");
	scanf("%d%d",&edges, &nodes);

	for(i = 0 ; i < edges ; i++) {
		scanf("%d%d%d",&v1,&v2,&wt);
		graph[v1][v2] = wt;
		graph[v2][v1] = wt;
	}

	printf("Running Floyd Warshall the Graph...\n");
	floyd_warshall(nodes);
	
	return 0;
}