#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        int n;
        cin>>n;
        if(n==0)break;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int m;
        cin>>m;
        int b[m];
        for(int i=0;i<m;i++)cin>>b[i];
        int s1=0,s2=0;
        int i=0,j=0;
        int ans=0;
        while(i<n && j<m){
            if(a[i]<b[j]) s1+=a[i++];
            else if(a[i]>b[j]) s2+=b[j++];
            else{
                ans+=max(s1,s2)+a[i];
                s1=s2=0;
                i++;
                j++;
            }
        }
        while(i<n)s1+=a[i++];
        while(j<m)s2+=b[j++];
        ans+=max(s1,s2);
        cout<<ans<<"\n";
    }
}