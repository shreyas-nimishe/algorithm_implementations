#include<bits/stdc++.h>
using namespace std;

void solveNQueens(vector< vector<bool> > &grid, int x, int y, int n ) {

}

int main() {
	int n;
	cout << "Enter the value of n:";
	cin >> n;

	if(n > 13) {
		cout << "Algorithm unable to generate config for n > 13";
		return 0;
	}
	vector< vector<bool> > grid;

	vector<bool> row;

	for(int i = 0 ; i < n ; i++) {
		row.clear();
		for(int j = 0 ; j < n ; j++) {
			row.push_back(0);
		}
		grid.push_back(row);
	}

	solveNQueens(grid, 0, 0, n);

	return 0;
}