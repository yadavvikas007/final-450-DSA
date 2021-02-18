#include <bits/stdc++.h>
using namespace std;
int trappingWater(int arr[], int n){

    int l=0,r=n-1;
    int leftmax=0,rightmax=0;
    int res=0;
    while(l<=r){
        if(arr[l]<=arr[r]){
            if(arr[l]>=leftmax)leftmax=arr[l];
            else res+=leftmax-arr[l];
            l++;
        }
        else{
            if(arr[r]>=rightmax) rightmax=arr[r];
            else res+=rightmax-arr[r];
            r--;
        }
        
    }
    return res;
    
    
}
int main(){
    int a[]={10,1,2,3,4,5,6,7,8,9};
    cout<<trappingWater(a,10);
}