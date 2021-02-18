#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int n=s.size();
        if(n<=0) return 0;
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++)  //base cases
            dp[i][i]=true;
        for(int i=0;i<n-1;i++){     
            dp[i][i+1]=(s[i]==s[i+1]);
        }
        for(int len=2;len<n;len++){
            for(int i=0,j=i+len;j<n;j++,i++){
                dp[i][j]=dp[i+1][j-1] && (s[i]==s[j]);
            }
        }
        int max=INT_MIN;
        int start=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] && j-i+1>max){
                    max=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start,max);
    }

int main(){
    string s="nitin";
    cout<<longestPalindrome(s);
}