#include <iostream>
using namespace std;

void rotate(int a[], int n) {
	int temp = a[n - 1];
	for (int i = n - 1; i > 0; i--) {
		a[i] = a[i - 1];
	}
	a[0] = temp;
}

void display(int a[], int n) {
	for (int i = 0; i < n; i++)
	{cout << a[i] << " ";}
	cout << endl;
}
int main() {
	int t , n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		rotate(a, n);
		display(a, n);
	}
	return 0;
}