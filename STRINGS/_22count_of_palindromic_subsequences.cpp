#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int solve(string s,int i,int j){
    if(i>j)return 0;
    if(i==j)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    
    if(s[i]==s[j]) 
    return dp[i][j]=dp[i][j]!=-1 ? dp[i][j] : solve(s,i+1,j)+solve(s,i,j-1)+1;
    else 
    return dp[i][j]=dp[i][j]!=-1 ? dp[i][j] : solve(s,i+1,j)+solve(s,i,j-1)-solve(s,i+1,j-1);
}
int countPS(string s)
{
    memset(dp,-1,sizeof(dp));
    return solve(s,0,s.size()-1);
}

int main(){
    string s="vikas";
    cout<<countPS(s);
}