#include<bits/stdc++.h>
using namespace std;

void printArray(int A[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void join(int *array, int start, int mid, int end) {
	int sublow[mid - start + 2], subupp[end - mid + 1], i, j, k;
	for(i = start ; i <= mid ; i++) {
		sublow[i-start] = array[i];
	}
	
	sublow[i-start] = 1e5;
	for(i = mid + 1; i <= end ; i++) {
		subupp[i-mid-1] = array[i];
	}

	subupp[i-mid-1] = 1e5;

	for(i = 0, j = 0, k = start ; k <= end ; k++) {
		if(sublow[i] <= subupp[j]) {
			array[k] = sublow[i];
			i++;
		}else{
			array[k] = subupp[j];
			j++;
		}
	}
}

void merge_sort(int *array, int start, int end) {
	int mid = (start + end)/2;
	if(start != end){
		merge_sort(array, start, mid);
		merge_sort(array, mid+1, end);

		join(array, start, mid, end);
	}
}

int main() {
	int myarr[] = {3 ,455, 54, 5454, 34, 68, 38, 86};
	int len = 8;
	printf("Unsorted : ");
	printArray(myarr, len);
	merge_sort(myarr, 0, len - 1);
	printf("\nSorted : ");
	printArray(myarr, len);
	return 0;
}