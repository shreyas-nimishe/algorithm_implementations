#include<bits/stdc++.h>
using namespace std;

void printArray(int A[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *array, int start, int end) {
	int pivot = array[end], i = start, j;

	for(j = start ; j < end ; j++) {
		if(array[j] <= pivot) {
			swap(&array[j], &array[i]);
			i++;
		}
	}

	swap(&array[i], &array[end]);
	return i;
}

void quick_sort(int *array, int start, int end) {
	
	if(start < end) {
		int pivot = partition(array, start, end);
		//printf("pivot = %d\n",pivot );
		quick_sort(array, start, pivot-1);
		quick_sort(array, pivot+1, end);
	}
}

int main() {
	int myarr[] = {3 ,455, 1, 54, 5454, 34, 68, 38, 86, 99};
	int len = 10;
	printf("Unsorted : ");
	printArray(myarr, len);
	quick_sort(myarr, 0, len - 1);
	printf("\nSorted : ");
	printArray(myarr, len);
	return 0;
}