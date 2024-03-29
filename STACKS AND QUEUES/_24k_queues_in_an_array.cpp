#include<iostream>
#include<climits>
using namespace std;
class kQueues{ 
	int *arr;
	int *front; 
	int *rear; 	 
	int *next; 
	int n, k;
	int free;
public:
	kQueues(int k, int n);
	bool isFull() { return (free == -1); }
	void enqueue(int item, int qn);
	int dequeue(int qn);
	bool isEmpty(int qn) { return (front[qn] == -1); }
};
kQueues::kQueues(int k1, int n1){
	k = k1, n = n1;
	arr = new int[n];
	front = new int[k];
	rear = new int[k];
	next = new int[n];
	for (int i = 0; i < k; i++)
		front[i] = -1;
	free = 0;
	for (int i=0; i<n-1; i++)
		next[i] = i+1;
	next[n-1] = -1;
}
void kQueues::enqueue(int item, int qn){
	if (isFull()){
		cout << "\nQueue Overflow\n";
		return;
	}
	int i = free;	 // Store index of first free slot
	// Update index of free slot to index of next slot in free list
	free = next[i];
	if (isEmpty(qn))
		front[qn] = i;  //inserting first element of qn
	else
		next[rear[qn]] = i;
	next[i] = -1;
	rear[qn] = i;// Update next of rear and then rear for queue number 'qn'
	arr[i] = item;
}
int kQueues::dequeue(int qn){
	if (isEmpty(qn)){
		cout << "\nQueue Underflow\n";
		return INT_MAX;
	}
	int i = front[qn];
	front[qn] = next[i]; // Change top to store next of previous top
	next[i] = free;
	free = i;
	return arr[i];
}
int main(){
	int k = 3, n = 10;
	kQueues ks(k, n);
	ks.enqueue(15, 2);
	ks.enqueue(45, 2);
	ks.enqueue(17, 1);
	ks.enqueue(49, 1);
	ks.enqueue(39, 1);
	ks.enqueue(11, 0);
	ks.enqueue(9, 0);
	ks.enqueue(7, 0);
	cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
	cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
	cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;
}