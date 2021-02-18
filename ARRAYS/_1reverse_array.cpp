#include <iostream>
using namespace std;

void reversearray(int a[], int l, int h)
{
	for (int i = l, j = h; i < j; i++, j--)
	{
		swap(a[i], a[j]);
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

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printarray(a, 10);
	reversearray(a, 0, 9);
	printarray(a, 10);
}