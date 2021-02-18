#include <bits/stdc++.h>
using namespace std;

void rearrange(int a[],int n){
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<"\n";
    int i=0,j=n-1;
    while(i<j){
        while(a[i]>=0)i++;
        while(a[j]<0)j--;
        if(i<j)
            swap(a[i],a[j]);
    }
    /*cout<<"after +ve to front and -ve to back\n";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<"\n";*/

    int k=0;
    while(k<i){
        if(a[i]<0 && a[k]>=0){
            swap(a[i],a[k]); 
            k+=2; i++;
        }
        else{k+=2; i++;}
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<"\n";

}

int main(){
    int a[]={1,-2};
    rearrange(a,2);
}