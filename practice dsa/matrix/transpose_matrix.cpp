#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &a){
    for(int i=0;i<a.size();i++){
        for(int j=i;j<a[0].size();j++){
            swap(a[i][j],a[j][i]);
        }
    }
}
void print(vector<vector<int>> &a)
{
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a( n , vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    transpose(a);
    print(a);
}