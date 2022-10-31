// C++ Program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Stores the sorted
// array elements
int temp[100000];

// Function to count the number of
// swaps required to merge two sorted
// subarray in a sorted form
long int merge(int A[], int left,
			int mid, int right)
{

	// Stores the count of swaps
	long int swaps = 0;

	int i = left, j = mid, k = left;

	while (i < mid && j <= right) {

		if (A[i] <= A[j]) {
			temp[k] = A[i];
			k++, i++;
		}
		else {
			temp[k] = A[j];
			k++, j++;
			swaps += mid - i;
		}
	}
	while (i < mid) {
		temp[k] = A[i];
		k++, i++;
	}

	while (j <= right) {
		temp[k] = A[j];
		k++, j++;
	}

	while (left <= right) {
		A[left] = temp[left];
		left++;
	}

	return swaps;
}

// Function to count the total number
// of swaps required to sort the array
long int mergeInsertionSwap(int A[],
							int left, int right)
{
	// Stores the total count
	// of swaps required
	long int swaps = 0;
	if (left < right) {

		// Find the middle index
		// splitting the two halves
		int mid = left + (right - left) / 2;

		// Count the number of swaps
		// required to sort the left subarray
		swaps += mergeInsertionSwap(A, left, mid);

		// Count the number of swaps
		// required to sort the right subarray
		swaps += mergeInsertionSwap(A, mid + 1, right);

		// Count the number of swaps required
		// to sort the two sorted subarrays
		swaps += merge(A, left, mid + 1, right);
	}
	return swaps;
}

// Driver Code
int main()
{
	int A[] = { 2, 1, 3, 1, 2 };
	int N = sizeof(A) / sizeof(A[0]);
	cout << mergeInsertionSwap(A, 0, N - 1);
	return 0;
}
