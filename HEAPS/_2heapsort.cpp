// C++ program for building Heap from Array 

#include <iostream> 

using namespace std; 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. N is size of heap 
void maxheapify(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		maxheapify(arr, n, largest); 
	} 
} 
 
// Function to build a Max-Heap from the given array 
void buildMaxHeap(int arr[], int n) 
{ 
	// Index of last non-leaf node 
	int startIdx = (n / 2) - 1; 

	// Perform reverse level order traversal 
	// from last non-leaf node and heapify 
	// each node 
	for (int i = startIdx; i >= 0; i--) { 
		maxheapify(arr, n, i); 
	} 
} 
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(arr, n, i);

    // Now One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        maxheapify(arr, i, 0);
    }
}

// A utility function to print the array 
// representation of Heap 
void printHeap(int arr[], int n) 
{ 
	cout << "Array representation of Heap is:\n"; 

	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printHeap(arr, n);
}
