// C++ program to find number of operations 
// to make an array palindrome 
#include <bits/stdc++.h> 
using namespace std; 

// Returns minimum number of count operations 
// required to make arr[] palindrome 
int findMinOps(int arr[], int n) 
{ 
	int ans = 0;
	for (int i=0,j=n-1; i<=j;) 
	{ 
		if (arr[i] == arr[j]){ //equal --> i++  , j--
            i++; j--; 
        }
		else if (arr[i] > arr[j]) {     //left greater
			j--; 
			arr[j] += arr[j+1] ; 
			ans++; 
        } 
		else{                           //right greater
			i++; 
			arr[i] += arr[i-1]; 
			ans++; 
		} 
	} 

	return ans; 
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = {1, 4, 5, 9, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout<< findMinOps(arr, n) << endl; 
	return 0; 
} 
