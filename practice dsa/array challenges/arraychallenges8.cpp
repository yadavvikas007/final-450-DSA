/*-----------Pair Target Sum Problem---------------
Find whether there exist 2 numbers that sum to K.
Important: The Array should be sorted for two pointer approach.
Idea: keep a low and high pointer, decide which pointer to move on the basis of
arr[low] + arr[high].
Time Complexity: O(N)
Space Complexity: O(1)           */

#include<iostream>
using namespace std;

bool pairsum(int a[],int n,int k){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==k){
                cout<<a[i]<<" "<<a[j]<<endl;
                return true;
            }
        }
    }
    return false;
}

bool pairsum1(int a[],int n,int k){
    int low=0,high=n-1;
    while(low<high){
        if(a[low]+a[high]==k){
            cout<<a[low]<<" "<<a[high]<<endl;
            return true;
        }
        else if(a[low]+a[high]>k) high--;
        else low++;
    }
    return false;
}

 int main()
 {
     int n,k;
     cin>>n>>k;
     int a[n];
     for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<pairsum1(a,n,k);
    return 0;
 }