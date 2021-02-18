#include <bits/stdc++.h>
using namespace std;


bool isValid(int arr[],int n,int m,int mid){
    int wood=0;
    for(int i=0;i<n;i++){ 
        if(arr[i]>=mid)
            wood=wood+(arr[i]-mid);
        }
    if(wood<m) return false;
    return true;
}

int requiredheight(int *arr, int n, int k) {
    int start = 0;
    int end= *max_element(arr,arr+n);
    int res;
    while(start<=end){
        int mid = start+((end-start)/2);
        if(isValid(arr,n,k,mid)){
            res=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<requiredheight(a,n,m)<<"\n";
}