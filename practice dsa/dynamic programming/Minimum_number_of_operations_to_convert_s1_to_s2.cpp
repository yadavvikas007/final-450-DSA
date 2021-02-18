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
	int minOperations(string s1, string s2) 
	{ 
	    int n=s1.size(),m=s2.size();
	    return n+m-2*(lcs(n,m,s1,s2));
	}

int main(){
    string s1="VIKAS";
    string s2="AKASH";
    cout<<minOperations(s1,s2);
}