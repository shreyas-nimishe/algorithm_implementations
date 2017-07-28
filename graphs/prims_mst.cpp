#include<bits/stdc++.h>
using namespace std;
#define N 10000

bool isVisited[N];
typedef pair<int, long long> PII;
std::vector< PII > adj[N];

long long primsMstSum() {
	long long mstSum = 0;
	int cur_node = 1, cur_dist;	

	priority_queue< PII, vector<PII>, greater<PII> > pq;
	pq.push(make_pair(0, cur_node));

	while(!pq.empty()) {
		cur_node = pq.top().second;
		cur_dist = pq.top().first;

		pq.pop();

		if(isVisited[cur_node])
			continue;

		isVisited[cur_node] = true;
		mstSum += cur_dist;

		for(int i = 0 ; i < adj[cur_node].size(); i++) {
			int next = adj[cur_node][i].first;

			if(!isVisited[next]) {
				pq.push(make_pair(adj[cur_node][i].second, next));
			}
		}
	}
	return mstSum;
}

int main() {
	int nodes, edges, v1, v2;
	long long wt;
	cin >> nodes >> edges;

	for(int i = 0 ; i < edges ; i++) {
		cin >> v1 >> v2 >> wt;

		adj[v1].push_back(make_pair(v2, wt));
		adj[v2].push_back(make_pair(v1, wt));
	}
	printf("%lld\n",primsMstSum());
	return 0;
}