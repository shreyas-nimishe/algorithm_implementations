#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll expo(ll a, ll exp, ll mod) {
	// this function computes (a^exp) % mod
	ll result = 1;

	while(exp) {
		if(a & 1) {
			result = (result * a) % mod;
			exp--;
		}

		exp >>= 1;		// divide by 2 
		a = (a * a) % mod;
	}
	return result;
}

int main() {
	ll A, B, C;
	printf("\nThis Program Computes (A^B) mod C \n\nEnter A, B & C: ");
	scanf("%lld%lld%lld",&A,&B,&C);
	printf("Reult: %lld\n", expo(A, B, C));
	return 0;
}