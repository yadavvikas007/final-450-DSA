#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int a[])      //O(N^2)
{
   int dp[n];
   dp[0]=1;
   for(int i=1;i<n;i++){
       dp[i]=1;
       for(int j=0;j<i;j++){
           if(a[i]>a[j] && dp[i]<=dp[j])    //greater than previous and including it increases max subseq. len
           dp[i]=1+dp[j];
       }
   }
   return *max_element(dp,dp+n);
}

int LIS(int a[],int n){         //O(NlogN)
    vector <int> seq;
    seq.push_back(a[0]);
    for(int i=0;i<n;i++){
        if(seq.back()<a[i])     
            seq.push_back(a[i]);
        else {
            int ind=lower_bound(seq.begin(),seq.end(),a[i])-seq.begin();
            seq[ind]=a[i];
        }
    }
    return seq.size();
}

int main(){
    int a[]={1,5,3,8,0};
    cout<<longestSubsequence(5,a)<<"\n";
    cout<<longestSUMSubsequence(5,a)<<"\n";
    cout<<LIS(a,5);
}