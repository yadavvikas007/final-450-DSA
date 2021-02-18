#include <iostream>
using namespace std;
int minjump(int a[],int n){     //time:O(n^2) space:O(n)
    int jumps[n];
        for(int i=0;i<n;i++) jumps[i]=INT32_MAX;
        jumps[0]=0;
        if(n<=1)return 0;
        if(a[0]==0)return -1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(i<=j+a[j]/*&&jumps[j]!=INT32_MAX*/){
                    jumps[i]=min(jumps[i],jumps[j]+1);
                    //break;
                }
            }
        }
        return jumps[n-1];
}

int minjump1(int a[],int n){    //time:O(n) space:O(1)
    if(n<=1)return 0;
    if(a[0]==0)return -1;
    int maxreach=a[0];
    int step=a[0];
    int jump=1;

    for(int i=1;i<n;i++){
        if(i==n-1)return jump;
        maxreach=max(maxreach,i+a[i]);
        step--;
        if(step==0){
            jump++;
            if(i>=maxreach)return -1;
            step=maxreach-i;
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<minjump1(a,n);
    }
}