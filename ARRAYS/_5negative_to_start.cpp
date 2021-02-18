//moving all negative to left
//Order of elements is not important here
#include <iostream>
using namespace std;

void rearrange(int a[], int n)		//2 pointer approach
{
	int i, j;
	i = 0; j = n - 1;
	while (i < j)
	{
		while (a[i] < 0)i++;
		while (a[j] > 0)j--;
		if (i < j) swap(a[i], a[j]);	//order not maintained
	}
}
void rearrange1(int a[], int n)		//partition process
{
	for (int i = 0, j = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			if (i != j)
				swap(a[i], a[j]);	//order maintained of -ve elements
			j++;
		}
	}
}
void rearrange2(int a[], int n)		//2 pointer approach
{
	int i, j;
	i = 0;
	j = n - 1;
	while (i < j)
	{
		if (a[i] < 0 && a[j] < 0) i++;
		else if (a[i] >= 0 && a[j] < 0) {swap(a[i], a[j]); i++; j--;}
		else if (a[i] >= 0 && a[j] >= 0) j--;
		else {i++; j--;}
	}
}
void reverse(int arr[], int l, int r)
{
	if (l < r) {
		swap(arr[l], arr[r]);
		reverse(arr, ++l, --r);
	}
}
void merge(int a[], int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	while (i <= m && a[i] < 0) i++;
	while (j <= r && a[j] < 0) j++;
	reverse(a, i, m);
	reverse(a, m + 1, j - 1);
	reverse(a, i, j - 1);
}
void rearrange3(int a[], int l, int r)	//order maintained optimised merge sort
{
	if (l < r)
	{
		int m = l + (r - l) / 2;	//to avoid overflows
		rearrange3(a, l, m);
		rearrange3(a, m + 1, r);
		merge(a, l, m, r);
	}
}
int main()
{
	int j;
	int a[] = {2, -1, 3, -2, 4, -3, -2, 8, -1, 3};
	for (j = 0; j < 10; j++) cout << a[j] << " ";
	cout << endl;
	rearrange3(a, 0, 9);
	for (j = 0; j < 10; j++) cout << a[j] << " ";
	cout << endl;
}