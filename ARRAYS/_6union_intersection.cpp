#include <iostream>
using namespace std;
void heapify(int a[], int n, int i)			//i is root of subtree ....O(logn)for heapify
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest]) largest = l;
	if (r < n && a[r] > a[largest]) largest = r;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void heapsort(int a[], int n)				//O(nlogn) best ,worst ,avg case
{
	for (int i = n / 2 - 1; i >= 0; i--)	//creating heap....O(n)
		heapify(a, n, i);
	for (int i = n - 1; i > 0; i--)			//stable and inplace algo
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
void printarray(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
bool not_in_c(int c[], int n, int key)
{
	if (n == 1) return true;
	for (int i = 0; i < n; i++)
		if (key == c[i])
			return false;
	return true;
}
//method 1 union 2 unsorted arrrays
/*void Union_unsorted(int a[], int b[], int n, int m)
{
	heapsort(a, n);
	heapsort(b, m);
	int *c = Union(a, b, n, m);
}*/
void Union(int a[], int b[], int n, int m)//method 2 sorting and union 2 unsorted arrays
{
	int c[n + m];
	int i = 0, j = 0, k = 0;
	heapsort(a, n);
	heapsort(b, m);
	while (i < n && j < m)
	{
		if (a[i] < b[j])
		{
			if (not_in_c(c, k + 1, a[i]))
				c[k++] = a[i++];
			else i++;
		}
		else if (b[j] < a[i])
		{
			if (not_in_c(c, k + 1, b[j]))
				c[k++] = b[j++];
			else j++;
		}
		else
		{
			if (not_in_c(c, k + 1, a[i]))
				c[k++] = a[i++];
			j++;
		}
	}
	while (i < n)
	{
		if (not_in_c(c, k + 1, a[i]))
			c[k++] = a[i++];
		else i++;
	}
	while (j < m)
	{
		if (not_in_c(c, k + 1, b[j]))
			c[k++] = b[j++];
		else j++;
	}
	printarray(c, k);
}
int binarySearch(int arr[], int l, int r, int x);
void printUnion(int arr1[], int arr2[], int m, int n)
{
	int c[n + m];
	int k = 0;
	// Before finding union, make sure arr1[0..m-1]
	// is smaller
	if (m > n) {
		int* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}

	// Now arr1[] is smaller

	// Sort the first array and print its elements (these
	// two steps can be swapped as order in output is not
	// important)
	heapsort(arr1, m);
	for (int i = 0; i < m; i++)
		c[k++] = arr1[i];

	// Search every element of bigger array in smaller array
	// and print the element if not found
	for (int i = 0; i < n; i++)
		if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
			c[k++] = arr2[i];
	printarray(c, k);
}//min(mLogm + nLogm, mLogn + nLogn)

// Prints intersection of arr1[0..m-1] and arr2[0..n-1]
void printIntersection(int arr1[], int arr2[], int m, int n)
{
	// Before finding intersection, make sure arr1[0..m-1]
	// is smaller
	if (m > n) {
		int* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}
	int c[m];
	int k = 0;

	// Now arr1[] is smaller

	// Sort smaller array arr1[0..m-1]
	heapsort(arr1, m);

	// Search every element of bigger array in smaller
	// array and print the element if found
	for (int i = 0; i < n; i++)
		if (binarySearch(arr1, 0, m - 1, arr2[i]) != -1)
			c[k++] = arr2[i];

	printarray(c, k);
}

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then it can only
		// be presen in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present in right
		// subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}
int main()
{
	int a[] = {85, 25, 32, 1, 1, 54, 6};
	int b[] = {85, 2};
	printUnion(a, b, 7, 2);
}
