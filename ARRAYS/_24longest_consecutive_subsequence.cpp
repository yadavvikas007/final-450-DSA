#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int a[], int n)
{
    int count=1;
    int ans=0;
    int hash[100000]={0};
    for(int i=0;i<n;i++)
        hash[a[i]]++;
  
    for(int i=0;i<99999;i++){
        if(hash[i]>0 && hash[i+1]>0)count++;
        else count=1;
        ans=max(ans,count);
    }
    return ans;
}
int main(){
    int a[]={1,2,3,4,5,6,10000};
    cout<<findLongestConseqSubseq(a,6);
}