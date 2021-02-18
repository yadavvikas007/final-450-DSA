#include <iostream>
using namespace std;
int getMinDiff(int a[], int n, int k) {
        vector <pair<int,int>> v;
        vector <int> visited(n);
        for(int i=0;i<n;i++){
            if(a[i]-k>=0)
                v.push_back({a[i]-k,i});
            v.push_back({a[i]+k,i});
        }
        sort(v.begin(),v.end());
        
        int ele=0;
        int left=0,right=0;
        
        while(ele<n && right<v.size()){
            if(visited[v[right].second]==0){
                ele++;
            }
            visited[v[right].second]++;
            right++;
        }
        
        int ans=v[right-1].first - v[left].first;
        
        while(right<v.size()){
            if(visited[v[left].second]==1)
                ele--;
            visited[v[left].second]--;
            left++;
            
            while(ele<n && right<v.size()){
                if(visited[v[right].second]==0){
                    ele++;
                }
                visited[v[right].second]++;
                right++;
            }
            
            if(ele==n)
                ans=min(ans,v[right-1].first - v[left].first);
            else
                break;
        }
        return ans;
        
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<getMinDiff(a,n,k);
    }
}