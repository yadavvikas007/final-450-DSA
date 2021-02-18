#include <bits/stdc++.h>
using namespace std;
 bool searchMatrix(vector<vector<int>>& a, int target) {
        if(a.size()==0||a[0].size()==0)return false;
        int n=a.size();
        int m=a[0].size();
        int low=0;
        int high=(n*m)-1;
        while(low<=high){
            int mid=(low+(high-low)/2);
            if(a[mid/m][mid%m]==target)return true;
            else if(a[mid/m][mid%m]<target)low=mid+1;
            else high=mid-1;
        }
        return false;
    }

 int main(){
    int n,m,target,flag=0;
    cin>>n>>m>>target;
    vector<vector<int>> a( n , vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    if(searchMatrix(a,target)) cout<<"found";
    else cout<<"not found";
 }
   
 