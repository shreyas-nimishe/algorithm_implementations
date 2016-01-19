#include<bits/stdc++.h>
using namespace std;

#define LIM 1000
int LCS[LIM][LIM], i, j;
string stra, strb;

int lcs(string a, string b) {
	int lena = stra.size(), lenb = strb.size();
	for(i = 0 ; i < lena ; i++) {
		for(j = 0 ; j < lenb ; j++) {
			if(i == 0 && j == 0)
				LCS[i][j] = (stra[0] == strb[0]);
			else if(i == 0)
				LCS[i][j] = (stra[i] == strb[j]) ? 1 : LCS[i][j-1];
			else if(j == 0)
				LCS[i][j] = (stra[i] == strb[j]) ? 1 : LCS[i-1][j];
			else
				LCS[i][j] = stra[i] == strb[j] ? LCS[i-1][j-1] + 1 : max(LCS[i-1][j], LCS[i][j-1]);

		}
	}
	return LCS[lena-1][lenb-1];
}

int main() {
	printf("This fuction computes the lenght of LCS of two strings\n Enter two strings: ");
	cin >> stra >> strb;
	printf("LCS = %d\n",lcs(stra, strb) );
	return 0;
}