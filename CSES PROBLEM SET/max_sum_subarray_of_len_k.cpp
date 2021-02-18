#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> a={3,5,1,4,0};
    int n=a.size();
    int k=3;
    int res=INT32_MIN;
    int i=0,j=0;
    int sum=0;
    while(j<n){
        sum+=a[j];
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            res=max(sum,res);
            sum-=a[i];
            i++; j++;
        }
    }
    cout<<res;
}