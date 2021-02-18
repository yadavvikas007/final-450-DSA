#include <bits/stdc++.h>
using namespace std;
 vector<int> nextPermutation(int N, vector<int> a){
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
        return a;
    }


    int main(){
        vector<int> a={1,3,2};
        vector<int> ans=nextPermutation(a.size(),a);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i];

    }