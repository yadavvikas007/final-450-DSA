#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& a) {
        int MIN=a[0];
        int MAX=a[0];
        int maxproduct=a[0];
        for(int i=1;i<a.size();i++){
            if(a[i]<0)swap(MIN,MAX);
            MIN=min(a[i],MIN*a[i]);
            MAX=max(a[i],MAX*a[i]);
            maxproduct=max(maxproduct,MAX);
        }
        return maxproduct;
    }

int main(){
    vector<int> a={1,2,-2,-1,0,5,3,-2,3,2};
    cout<<maxProduct(a);
}