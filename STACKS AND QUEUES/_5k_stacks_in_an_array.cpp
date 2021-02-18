// A C++ program to demonstrate implementation of k stacks in a single 
// array in time and space efficient way 
#include<bits/stdc++.h> 
using namespace std; 

class kStacks 
{ 
	int *stackData; // Array of size n to store actual content to be stored in stacks 
	int *topOfStack; // Array of size k to store indexes of top elements of stacks 
	int *nextIndex; // Array of size n to store next entry in all stacks and free list  
	int n, k; 
	int nextAvailable; // To store beginning index of free list 
public: 
	kStacks(int k, int n); 
	bool isFull() { return (nextAvailable == -1); } 
	void push(int item, int sn); 
	int pop(int sn);
    int topvalue(int sn); 
	bool isEmpty(int sn) { return (topOfStack[sn] == -1); } 
}; 

kStacks::kStacks(int k1, int n1) { 
	k = k1, n = n1; 
	stackData = new int[n]();

	topOfStack = new int[k];
    for (int i = 0; i < k; i++) 
		topOfStack[i] = -1;  

	nextAvailable = 0;

    nextIndex = new int[n]; 
	for (int i=0; i<n-1; i++) 
		nextIndex[i] = i+1; 
	nextIndex[n-1] = -1;
} 

// To push an item in stack number 'sn' where sn is from 0 to k-1 
void kStacks::push(int item, int sn) {
	if (isFull()) { 
		cout << "\nStack Overflow\n"; 
		return; 
	} 
	int i = nextAvailable;	 // Store index of first free slot 
	// Update index of free slot to index of next slot in free list 
	nextAvailable = nextIndex[i]; 
	// Update next of top and then top for stack number 'sn' 
	nextIndex[i] = topOfStack[sn]; 
	topOfStack[sn] = i; 
	stackData[i] = item; 
} 

// To pop an from stack number 'sn' where sn is from 0 to k-1 
int kStacks::pop(int sn) {
	if (isEmpty(sn)) {
		cout << "\nStack Underflow\n"; 
		return INT_MAX; 
	}
	// Find index of top item in stack number 'sn'
	int i = topOfStack[sn];
	topOfStack[sn] = nextIndex[i]; // Change top to store next of previous top 
	// Attach the previous top to the beginning of free list 
	nextIndex[i] = nextAvailable;
	nextAvailable = i;
	return stackData[i];
} 

int kStacks::topvalue(int sn){
    return stackData[topOfStack[sn]];
}

/* Driver program to test twStacks class */
int main() 
{ 
	// Let us create 3 stacks in an array of size 10 
	int k = 3, n = 10; 
	kStacks ks(k, n); 

	// Let us put some items in stack number 2 
	ks.push(15, 2); 
	ks.push(45, 2); 

	// Let us put some items in stack number 1 
	ks.push(17, 1); 
	ks.push(49, 1); 
	ks.push(39, 1); 

	// Let us put some items in stack number 0 
	ks.push(11, 0); 
	ks.push(9, 0); 
	ks.push(7, 0); 

	cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
	cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
	cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
    cout << "top of stack 2 : "<<ks.topvalue(2);

	return 0; 
} 
