#include <bits/stdc++.h>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
        int n=s1.size() ;int m=s2.size();
        int t[1001][1001]={0};          //t[0][0]=0
        
        t[1][0]=s1[0];          
        for(int i=2;i<=n;i++)t[i][0]=t[i-1][0]+s1[i-1];
        
        t[0][1]=s2[0];
        for(int j=2;j<=m;j++)t[0][j]=t[0][j-1]+s2[j-1];
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    t[i][j]=t[i-1][j-1];
                else 
                    t[i][j]=min(t[i-1][j]+s1[i-1] , t[i][j-1]+s2[j-1]);
            }
        }
        return t[n][m];
    }

int main(){
    string s1="vikas";
    string s2="akash";
    cout<<minimumDeleteSum(s1,s2);
}