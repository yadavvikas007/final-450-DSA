#include <bits/stdc++.h>
using namespace std;

int minjumps(int a[],int n){
    int res[n],jumps[n];
    int I=INT32_MAX-1;
    jumps[0]=0;
    res[0]=0;
    for(int i=1;i<n;i++)
        jumps[i]=I;
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]+j>=i){
                if(jumps[j]+1<jumps[i]){
                    jumps[i]=jumps[j]+1;
                    res[i]=j;
                }
            }
        }
    }
    return jumps[n-1];
}

int main(){
    int a[]={1,2,-3,4,5,-6,-7,-8,9,10};
    cout<<minjumps(a,10);
}