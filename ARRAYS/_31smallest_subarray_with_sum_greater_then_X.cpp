#include <bits/stdc++.h>
using namespace std;

int sb(int a[], int n, int x)
{
       int curr_sum=0;
       int minlen=n;
       int start=0,end=0;
       while(end<n){
           while(curr_sum<=x && end<n) curr_sum+=a[end++];
           while(curr_sum>x && start<n){
               minlen=min(minlen,end-start);
               curr_sum-=a[start++];
           }
       }
       return minlen;
}
int main(){
    int a[]={1,2,3,9,8,7,6,5,4,10};
    cout<<sb(a,10,10);
}