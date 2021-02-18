#include <bits/stdc++.h>
using namespace std;

int duplicate(int a[],int n){       //time:O(nlogn) space:O(1)
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            return a[i];
        }
    }
    return -1;
}
int duplicate1(int a[],int n){      //time:O(n) space:O(n)
    int hash[1000]={0};
    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }
    for(int i=0;i<1000;i++){
        if(hash[i]>1)return i;
    }
    return -1;
}
int duplicate2(int nums[],int n){      //time:O(n) space:O(1) [floyd tortoise and hare cycle detecting algorithm]
    int tortoise = nums[0];
    int hare = nums[0];
    do {
      tortoise = nums[tortoise];
      hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Find the "entrance" to the cycle.
    tortoise = nums[0];
    while (tortoise != hare) {
      tortoise = nums[tortoise];
      hare = nums[hare];
    }

    return hare;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<duplicate2(a,n);
    }
}