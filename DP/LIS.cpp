#include<bits/stdc++.h>
using namespace std;

int CeilIndex(std::vector<int>& v, int low, int up, int key) 
{ 
    while (up - low > 1) { 
        int mid = low + (up - low) / 2; 
        if (v[mid] >= key) 
            up = mid;
        else
            low = mid;
    } 
  
    return up; 
} 
  
int lis(std::vector<int>& v) 
{ 

	int n = v.size();
    if (n == 0) 
        return 0; 
  
    vector<int> tail(n, 0); 
    int length = 1; // always points empty slot in tail 
  
    tail[0] = v[0]; 
    for (int i = 1; i < n; i++) { 

        if (v[i] < tail[0]) {
            tail[0] = v[i]; 
        } else if (v[i] > tail[length - 1]) {
            tail[length++] = v[i]; 
        } else{
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
        }
    } 
  
    return length; 
} 

int main() {
	vector<int> nums = {1,56, 23, 36, 334, 4, 57, 90};

	printf("ARRAY: ");
	for(int i = 0 ; i < nums.size() ; i++) {
		printf(" %d |", nums[i] );
	}

	printf("\nLIS lenght = %d\n", lis(nums) );
	return 0;
	
}