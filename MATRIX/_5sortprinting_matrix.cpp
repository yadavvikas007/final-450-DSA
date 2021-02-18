#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
#define N 4
void Print(vector<vector<int>> a, int n,int m){
    vector<int> b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b.push_back(a[i][j]);
        }
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n*m;i++)
        cout<<b[i]<<" ";
        
    }

void youngify(vector<vector<int>> &mat, int i, int j)       //O(N)
{ 
    // Find the values at down and right sides of mat[i][j] 
    int downVal  = (i+1 < N)? mat[i+1][j]: INF; 
    int rightVal = (j+1 < N)? mat[i][j+1]: INF; 
  
    // If mat[i][j] is the down right corner element, return 
    if(downVal==INF && rightVal==INF) 
        return; 
  
    // Move the smaller of two values (downVal and rightVal) to  
    // mat[i][j] and recur for smaller value 
    if (downVal < rightVal) 
    { 
        mat[i][j] = downVal; 
        mat[i+1][j] = INF; 
        youngify(mat, i+1, j); 
    } 
    else
    { 
        mat[i][j] = rightVal; 
        mat[i][j+1] = INF; 
        youngify(mat, i, j+1); 
    } 
} 
  
// A utility function to extract minimum element from Young tableau 
int extractMin(vector<vector <int>> &mat ) 
{ 
    int ret = mat[0][0]; 
    mat[0][0] = INF; 
    youngify(mat, 0, 0); 
    return ret; 
}
// This function uses extractMin() to print elements in sorted order 
void printSorted(vector<vector<int>> &mat)   //using young tableau method O(N^3)
{ 
   for (int i=0; i<N*N; i++) 
     cout << extractMin(mat) << " "; 
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
    printSorted(a);
}