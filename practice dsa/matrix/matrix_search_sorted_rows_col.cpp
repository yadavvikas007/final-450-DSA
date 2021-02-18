#include<bits/stdc++.h>
using namespace std;

bool Search(vector<vector<int>> a,int n,int m,int target){
    int r=0,c=m-1;
    while(r<n && c>=0){
        if(target==a[r][c]) return true;
        else if(target > a[r][c]) r++;
        else c--;
    }
    return false;
}

int main(){
    int n,m,target;
    cin>>n>>m>>target;
    vector<vector<int>> a( n , vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    if(Search(a,n,m,target)) cout<<"found";
    else cout<<"not found";
}