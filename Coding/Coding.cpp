#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;

void heapify(int arr[], int i, int n) {
	int left = 2 * i;
	int right = 2 * i + 1;
	
	int largest = i;

	if (left <= n && arr[largest] < arr[left]) {
		largest = left;
	}
	if (right <= n && arr[largest] < arr[right]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[largest], arr[i]);
		heapify(arr, largest, n);
	}
}

void heapsort(int arr[], int n) {
	for (int i = n / 2; i > 0; i--) {
		heapify(arr, i, n);
	}
	while (n > 1)
	{
		swap(arr[1], arr[n]);
		n--;
		heapify(arr, 1, n);
	}
}
int main() {
	int arr[] = {-1, 4,2,9,1,3,5,6,2,0,11,34};
	heapsort(arr, 11);

	for (int i = 1; i < 12; i++)
		cout << arr[i] << " ";
	return 0;
}

/*
6
7
1 2
2 3
1 3
4 1
4 5
5 6
6 4
*/