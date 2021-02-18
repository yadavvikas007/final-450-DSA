#include<bits/stdc++.h>
using namespace std;

    void nextPermutation(vector<int>& a) {
        int n=a.size(),i,l;
        for(i=n-2;i>=0;i--){
            if(a[i]<a[i+1]) break;
        }
        if(i<0){
            reverse(a.begin(),a.end());
        }
        else{
            for(l=n-1;l>i;l--){
                if(a[l]>a[i]) break;
            }
            swap(a[i],a[l]);
            reverse(a.begin()+i+1,a.end());
        }
    }

int main(){
    int n,input;
    cin>>n;
    vector<int> a;
    while(n--){
        cin>>input;
        a.push_back(input);
    }
    nextPermutation(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i];
    }
}