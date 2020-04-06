#include<bits/stdc++.h>
using namespace std;
#define LIM 100002
bool isprime[LIM];
int prime[9594], i, j, n;

int main() {
	for(i = 2 ; i < 350 ; i++) {
		if(!isprime[i]) {
			for(j = i*i ; j < LIM ; j += i) {
				isprime[j] = 1;
			}
		}
	}

	for(i = 2, j = 0 ; i < LIM ; i++) {
		if(!isprime[i])		prime[j++] = i;
	}

	printf("This Program pre-computes primes less than 10^5 i.e first 9593 primes\nEnter the no of primes to be printed: ");
	scanf("%d",&n);
	n = min(9592, n);
	for(i = 0 ; i < n ; i++) {
		printf("%d\n",prime[i]);
	}
	return 0;
}