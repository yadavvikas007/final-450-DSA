#include <iostream>
#include <climits>
using namespace std;

struct Pair
{
	int ksmall;
	int klarge;
};

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
Pair kth_smallest_and_largest(int a[], int n, int k)
{
	Pair s;
	heapsort(a, n);			//sorting O(NlogN)
	s.ksmall = a[k - 1];
	s.klarge = a[n - k];
	return s;
}



int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
int randomPartition(int arr[], int l, int r)
{
	int n = r - l + 1;
	int pivot = rand() % n;
	swap(arr[l + pivot], arr[r]);
	return partition(arr, l, r);
}
int kth_smallest_1(int a[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int pos = randomPartition(a, l, r);
		if (pos - l == k - 1)
			return a[pos];
		if (pos - l > k - 1)
			return kth_smallest_1(a, l, pos - 1, k);
		return kth_smallest_1(a, pos + 1, r, k - pos + l - 1);
	}
	else return INT_MAX;
}
int kth_largest_1(int a[], int l, int r, int n, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int pos = randomPartition(a, l, r);
		if (pos - l == n - k)
			return a[pos];
		if (pos - l > k - 1)
			return kth_largest_1(a, l, pos - 1, n, k);
		return kth_largest_1(a, pos + 1, r, n, k - pos + l - 1);
	}
	else return INT_MAX;
}




void printarray(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int k;
	int a[] = {3, 4, 2, 5, 6, 9, 1, 7, 10, 8};
	printarray(a, 10);
	k = 3;
	Pair s = kth_smallest_and_largest(a, 10, k);
	cout << k << "th largest element in array is:" << s.klarge ;
	cout << "\n" << k << "th smallest element in array is:" << s.ksmall;

	cout << "\n" << kth_smallest_1(a, 0, 9, k) << "\n";
	cout << kth_smallest_1(a, 0, 9, 10 - k + 1);
}