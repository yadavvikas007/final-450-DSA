#include <bits/stdc++.h>
using namespace std;

/*string shortestCommonSupersequence(string s1, string s2) {
        int a=s1.size(),b=s2.size();
        int t[a+1][b+1];
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                if(j==0 || i==0) t[i][j]=0;
            }
        }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(s1[i-1]==s2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
        int i=a,j=b;
        string ans;
        
        while(i>0 && j>0){      //traversing the t matrix backwards and generating SCS
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--; j--;
            }
            else{
                if(t[i][j-1]>t[i-1][j]){
                    ans+=s2[j-1];
                    j--;
                }
                else if(t[i-1][j]>t[i][j-1]){
                    ans+=s1[i-1];
                    i--;
                }
            }
        }
        while(j){
            ans+=s2[j-1];
            j--;
        }
        while(i){
            ans+=s1[i-1];
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }*/
string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                } else {
                    if(str1[i-1] == str2[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
        
        int i = n;
        int j = m;
        string ans;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans+= str1[i-1];
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]){
                ans+= str1[i-1];
                i--;
            } else {
                ans+= str2[j-1];
                j--;
            }
        }
        
        while(j){
            ans+= str2[j-1];
            j--;
        }
        
        while(i){
            ans+= str1[i-1];
            i--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
int main(){
    string s1="vikas";
    string s2="akash";
    cout<<shortestCommonSupersequence(s1,s2);
}