#include<bits/stdc++.h>
using namespace std;

#define LIM 21

int parent[LIM], totalCount[LIM];

void createSet(int v1) {
	parent[v1] = v1;
	totalCount[v1] = 1;
}

int getSetRoot(int v1) {
	if(parent[v1] == v1)	return v1;

	return parent[v1] = getSetRoot(parent[v1]);
}

void mergeSet(int v1, int v2) {
	v1 = getSetRoot(v1);
	v2 = getSetRoot(v2);

	if(v1 == v2)	return ;

	if(totalCount[v2] >= totalCount[v2]) {
		totalCount[v2] += totalCount[v1];
		//printf("totalCount[%d] = %d\n",v2,  totalCount[v2] );
		parent[v1] = v2;
	}else{
		totalCount[v1] += totalCount[v2];
		//printf("totalCount[%d] = %d\n",v1, totalCount[v1] );
		parent[v2] = v1;
	}
}

int main() {

	for(int i = 0 ; i <= LIM ; i++) {
		createSet(i);
	}

	for(int i = 0 ; i < 10 ; i++) {
		int c1 = rand() % LIM + 1, c2 = rand() % LIM + 1;
		printf("Merging set of %d & %d \n", c1, c2);
		mergeSet(c1, c2);
		printf("Common root = %d, sizeOfSet = %d\n\n", getSetRoot(c1), totalCount[getSetRoot(c1)] );
	}
	return 0;
}