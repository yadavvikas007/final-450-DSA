#include<iostream>
using namespace std;

int minswaps(int a[],int n,int k){
    int l=0,h=n-1;
    int ct=0,bad=0;
    for(int i=0;i<n;i++){
        if(a[i]<=k) ct++;
    }
    
    for(int i=0;i<ct;i++){
        if(a[i]>k)bad++;
    }
    int ans=bad;
    for(int j=0,i=ct;i<n;i++,j++){
        if(a[j]>k) bad--;       
        if(a[i]>k) bad++;
        ans=min(ans,bad);
    }
    
    return ans;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int k;
	    cin>>k;
	    cout<<minswaps(a,n,k)<<"\n";
	}
	return 0;
}