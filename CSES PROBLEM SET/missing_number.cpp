#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int h[n+1]={0};
    int input;
    for(int i=0;i<n-1;i++){
        cin>>input;
        h[input]=1;
    }
    for(int i=1;i<=n;i++){
        if(!h[i]) cout<<i;
    }
}