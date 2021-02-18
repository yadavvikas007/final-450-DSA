/*Problem
Given an array arr[] of size N. The task is to find the first repeating element in an
array of integers, i.e., an element that occurs more than once and whose index of
first occurrence is smallest.  */

#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int Min = 100000;
		const int N = 100002;
		int h[N];
		for (int i = 0; i < N; i++) {
			h[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			if (h[a[i]] != -1) {
				Min = min(Min, h[a[i]]);
			}
			else {
				h[a[i]] = i;
			}
		}
		if (Min == 100000)cout << "-1" << endl;
		else cout <<a[Min]<<" "<< Min << endl;
	}
}