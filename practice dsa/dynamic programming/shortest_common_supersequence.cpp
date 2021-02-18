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
int shortestCommonSupersequence(string X, string Y, int m, int n) {
    //for(int i=0;i<m;i++) if(X[i]>='a'&&X[i]<='z')X[i]=X[i]-32;
    //for(int i=0;i<n;i++) if(Y[i]>='a'&&Y[i]<='z')Y[i]=Y[i]-32;
    int l=lcs(m,n,X,Y);
    return (m+n)-l;
}

int main(){
    string s1="vikas";
    string s2="akash";
    cout<<shortestCommonSupersequence(s1,s2,s1.size(),s2.size());
}