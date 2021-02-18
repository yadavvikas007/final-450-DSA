#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int mat[MAX][MAX];
typedef pair<int, pair<int, int>> pi; 

int kthSmallest(int n, int k)
{
priority_queue <pi, vector<pi>, greater<pi> > pq;   //minheap
for(int j=0;j<n;j++){
    pq.push(make_pair(mat[0][j],make_pair(0,j)));       //pushing first row
}
int ans = -1;
pair<int, pair<int, int>> pp;       //storing top of pq
while(k--) {
    pp = pq.top();
    pq.pop();
    int r = pp.second.first;        //row of minimum poped
    int c = pp.second.second;       //col of minimum poped
    if(r+1<n){                      
       pq.push(make_pair(mat[r+1][c],make_pair(r+1,c))); 
    }
}
return pp.first;
    
}

int main(){
    int n=4;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int k=3;
    cout<<kthSmallest(4,k);
}