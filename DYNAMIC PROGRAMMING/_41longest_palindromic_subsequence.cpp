#include <bits/stdc++.h>
using namespace std;

int lcs(int a, int b, string s1, string s2){
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
    return t[a][b];
    
}
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        int n=s.size();
        return lcs(n,n,s,s1);
    }

int main(){
    string s="vikas";
    cout<<longestPalindromeSubseq(s);
}