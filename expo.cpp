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
	printf("(41^12) mod 2344 = %lld\n",expo(41, 12, 2344));
	return 0;
}