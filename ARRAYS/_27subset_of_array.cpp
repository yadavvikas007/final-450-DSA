#include<bits/stdc++.h>
using namespace std;

bool issubset(int a[],int b[],int n,int m){
    if(n<m)return false;
    unordered_set <int> hash;
    for(int i=0;i<n;i++)
        hash.insert(a[i]);
    for(int i=0;i<m;i++){
        if(hash.find(b[i])==hash.end())
            return false;
    }
    return true;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n ,m;
	    cin>>n>>m;
	    int a[n],b[m];
	    for(int i=0;i<n;i++) cin>>a[i];
	    for(int i=0;i<m;i++) cin>>b[i];
	    if(issubset(a,b,n,m))cout<<"Yes\n";
	    else cout<<"No\n";
	}
	return 0;
}