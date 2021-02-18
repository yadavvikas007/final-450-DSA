#include <bits/stdc++.h>
using namespace std;

int longestSUMSubsequence(int n, int a[])       //O(N^2)
{
   int dp[n];
   dp[0]=a[0];
   for(int i=1;i<n;i++){
       dp[i]=a[i];
       for(int j=0;j<i;j++){
           if(a[i]>a[j] && dp[i]<dp[j]+a[i])    //greater than previous and including it increases maxsum
           dp[i]=a[i]+dp[j];
       }
   }
   return *max_element(dp,dp+n);
}
int main(){
    int a[]={1,2,3,4,4};
    cout<<longestSUMSubsequence(5,a);
}