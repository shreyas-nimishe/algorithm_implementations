#include<bits/stdc++.h>
using namespace std;
#define LIM 100005

void swap(int *a, int *b)  {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void heapify(int inputArray[], int idx, int size) {
	int right_idx = 2*idx + 1, left_idx = 2*idx + 2, largest = idx;

	if(right_idx < size && inputArray[right_idx] > inputArray[idx] ) {
		largest = right_idx;
	}

	if(left_idx < size && inputArray[left_idx] > inputArray[largest]) {
		largest = left_idx;
	}

	if(largest != idx) {
		//printf("%d %d %d => %d\n",inputArray[idx], inputArray[right_idx], inputArray[left_idx], inputArray[largest] );
		swap(inputArray[largest], inputArray[idx]);
		heapify(inputArray, largest, size);
	}
}

void printArr(int inputArr[], int size) {
    for (int i = 0; i < size ; ++i)
        cout << inputArr[i] << " ";

    printf("\n");
}

void create_heap(int inputArray[], int size) {
	for(int i = size/2 ; i >= 0; i--) {
		//printArr(inputArray, size);
		heapify(inputArray, i, size);
		//printf("\ni = %d\n",i );
		//printArr(inputArray, size);
	}
}

void heap_sort(int inputArray[], int size) {
	int len = size;
	create_heap(inputArray, size);

	for(int i = 0 ; i < size - 1 ; i++) {
		swap(&inputArray[0], &inputArray[len-1]);
		len--;
		heapify(inputArray, 0, len);
	}
}
 
int main() {
    int inputArr[] = {182, 311, 1345, 455, 456, 745, 74};
    int n = sizeof(inputArr)/sizeof(inputArr[0]);
 	//create_heap(inputArr, n);
 	printf("Original input Array: ");
 	printArr(inputArr, n);

 	create_heap(inputArr, n);
 	printf("After Creating Max Heap: ");
 	printArr(inputArr, n);

 	heap_sort(inputArr, n);
 	printf("After Applying heap sort: ");
    printArr(inputArr, n);
 
    return 0;
}
