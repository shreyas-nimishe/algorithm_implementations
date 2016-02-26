#include<bits/stdc++.h>
using namespace std;
#define LIM 100005

int segment[4*LIM], array[LIM], lazy[4*LIM];
// Segment tree that computes maximum in a range, and can be incremented in a range

void build(int node_lower, int node_upper, int node_idx) {
	if(node_lower > node_upper )	return;

	if(node_upper == node_lower){
		segment[node_idx] = array[node_lower];
	}
	int mid = (node_upper + node_lower) / 2;
	build(node_lower, mid, 2*node_idx);			// tree is one based i.e indexing begins from 1
	build(mid + 1, node_upper, 2*node_idx + 1);

	segment[node_idx] = max(segment[2*node_idx], segment[2*node_idx + 1]);
}

void update(int range_lower, int range_upper, int node_lower, int node_upper, int inc, int node_idx) {

	if(lazy[node_idx] != 0) {
		segment[node_idx] += lazy[node_idx];
		if(node_upper != node_upper) {
			lazy[2*node_idx] += lazy[node_idx];
			lazy[2*node_idx + 1] += lazy[node_idx];
		}
		lazy[node_idx] = 0;
	}

	if(range_lower > node_upper || node_lower > node_upper || node_lower > range_upper)		return;

	if(range_lower <= node_lower && node_upper <= range_upper) {
		lazy[node_idx] = inc;
		return;
	}else{
		int mid = (node_lower + node_upper) / 2;
		update(range_lower, range_upper, node_lower, mid, inc, 2*node_idx);
		update(range_lower, range_upper, mid + 1, node_upper, inc, 2*node_idx + 1);

		segment[node_idx] = max(segment[2*node_idx], segment[2*node_idx + 1]);
	}
}

int query(int range_lower, int range_upper, int node_lower, int node_upper, int node_idx) {
	if(lazy[node_idx] != 0) {
		segment[node_idx] += lazy[node_idx];
		if(node_lower != node_upper) {
			lazy[2*node_idx] += lazy[node_idx];
			lazy[2*node_idx + 1] += lazy[node_idx];
		}
		lazy[node_idx] = 0;
	}

	if(range_lower > node_upper || range_upper < node_lower || node_lower > node_upper)		return 0;	// return -INF if negetive numbers are present in input
	
	if(range_lower <= node_lower && node_upper <= range_upper) {
		return segment[node_idx];
	}else{
		int mid = (node_lower + node_upper) / 2;
		return max(query(range_lower, range_upper, node_lower, mid, 2*node_idx), query(range_lower, range_upper, mid + 1, node_upper, 2*node_idx + 1));
	}	
}

int main() {
	printf("Q] Given an array perform the following two operations\n\t1] Increment elements in a given range\n\t2] Obtain the maximum element in a given range\n");
	
	return 0;
}