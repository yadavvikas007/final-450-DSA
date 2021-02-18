#include<bits/stdc++.h>
using namespace std;

int mindiff(int a[],int n,int m ){
    if(n==0 ||m==0)return 0;
    if(m>n)return -1;
    sort(a,a+n);
    
    int ans=a[m-1]-a[0];
    int l=1,h=m;
    while(h<n){
        if(a[h]-a[l]<ans)
            ans=a[h]-a[l];
        l++; h++;
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
	    int m;
	    cin>>m;
	    cout<<mindiff(a,n,m);
	    cout<<"\n";
	}
	return 0;
}