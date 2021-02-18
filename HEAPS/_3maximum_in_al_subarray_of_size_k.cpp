// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int n, int k)
{
	std::deque<int> Qi(k);
	int i;
	for (i = 0; i < k; ++i){
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();
		Qi.push_back(i);
		
	}
	// Process rest of the elements, 
	// i.e., from arr[k] to arr[n-1]
	for (; i < n; ++i) {
		cout << arr[Qi.front()] << " ";
		while ((!Qi.empty()) && Qi.front() <= i - k)
			Qi.pop_front();

		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();
		Qi.push_back(i);
		
	}
	cout << arr[Qi.front()]<<" ";
}

// Driver code
int main()
{
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	printKMax(arr, n, k);
	return 0;
}
