#include <iostream>
using namespace std;

/*void spiraltraverse(int **a ,int n,int m){
    int rows=0,cols=0;
    int rowe=n-1,cole=m-1;
    while(rows<=rowe && cols<=cole){
        for(int i=cols;i<cole;i++){cout<<a[rows][i]<<" "; }rows++; 
        for(int i=rows;i<rowe;i++){cout<<a[i][cole]<<" "; }cole--; 
        for(int i=cole;i>=cols;i--){cout<<a[rowe][i]<<" "; }rowe--; 
        for(int i=rowe;i>=rowe;i--){cout<<a[i][cols]<<" "; }cols++;
    }
}*/

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int rows=0,cols=0,count=0;
    int rowe=n-1,cole=m-1;
    while(rows<=rowe && cols<=cole &&count<n*m){
        for(int i=cols;i<=cole&&count<n*m;i++){ cout<<a[rows][i]<<" ";count++; }rows++; 
        for(int i=rows;i<=rowe&&count<n*m;i++){ cout<<a[i][cole]<<" ";count++; }cole--; 
        for(int i=cole;i>=cols&&count<n*m;i--){ cout<<a[rowe][i]<<" ";count++; }rowe--; 
        for(int i=rowe;i>=rows&&count<n*m;i--){ cout<<a[i][cols]<<" ";count++; }cols++;
    }
}