#include<bits/stdc++.h>
using namespace std;

int dp[30][30];
int bracket[30][30];
void printParenthesis(int i, int j, char &name) {
    if (i == j){
        cout << name++; 
        return; 
    } 
    cout << "("; 
    printParenthesis(i, bracket[i][j], name); 
    printParenthesis(bracket[i][j] + 1, j, name); 
    cout << ")"; 
} 
int solve(int arr[], int i, int j){
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int left=dp[i][k]!=-1 ? dp[i][k] :  solve(arr,i,k);
        int right=dp[k+1][j]!=-1 ? dp[k+1][j] :  solve(arr,k+1,j);
        int temp = left+right+ arr[i-1]*arr[k]*arr[j];
        if(temp<ans){
            ans = temp;
            bracket[i][j]=k;        //saving min cost partition place(k) in array(i,j)
        }
    }
    return dp[i][j] = ans;          //saving min cost of multipl. in array(i,j)
}

int main() 
{ 
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(bracket,-1,sizeof(bracket));
        int n;
        cin>>n;
        int v[n];
        for(int i=0;i<n;i++)
            cin>>v[i];
        solve(v,1,n-1);
        char name='A';
        printParenthesis(1, n-1,  name);
        cout<<endl;
    }
    return 0; 
}