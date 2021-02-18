#include <bits/stdc++.h>
using namespace std;

int lcs(int a, int b, string s1, string s2){
    int t[2][b+1];

    bool bi;
    for(int i=0;i<=a;i++){
        bi=i&1;
        for(int j=0;j<=b;j++){
            if(j==0 || i==0) t[bi][j]=0;
            else if(s1[i-1]==s2[j-1])
                t[bi][j]=1+t[1-bi][j-1];
            else t[bi][j]=max(t[bi][j-1],t[1-bi][j]);
        }
    }
    return t[bi][b];
    
}
int main(){
    string s="vikas";
    string t=".v.i.k.a.s.";
    cout<<lcs(s.size(),t.size(),s,t);
    
}