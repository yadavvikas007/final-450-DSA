#include <bits/stdc++.h>
using namespace std;
bool find3Numbers(int a[], int n, int x)
{
    if(n<3)return false;
    sort(a,a+n);
    for(int i=0;i<n-2;i++){
        int rem=x-a[i];
        int l=i+1,h=n-1;
        while(l<h){
            if(a[l]+a[h] == rem)return true;
            else if(a[l]+a[h]>rem)h--;
            else l++;
        }
    }
    return false;
}

int main(){
    int a[]={1,2,3,4,5,6,7,8,9};
    if(find3Numbers(a,9,18))cout<<"YES";
    else cout<<"NO";
}