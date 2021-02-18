#include<bits/stdc++.h>
using namespace std;
int maximum(int a,int b,int c){
    return max(a,max(b,c));
}
int lcs(string s1, string s2,string s3,int a,int b,int c) {
    
    int t[a+1][b+1][c+1];

    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++)
            for(int k=0; k<=c; k++){
                if(j==0 || i==0 ||k==0) t[i][j][k]=0;
                
                else if(s1[i-1]==s2[j-1] && s1[i-1]==s3[k-1])
                    t[i][j][k]=1+t[i-1][j-1][k-1];
                    
                else t[i][j][k]=maximum(t[i-1][j][k],
                                        t[i][j-1][k],
                                        t[i][j][k-1]);
        }
    }
    return t[a][b][c];
    }
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s1,s2,s3;
	    int n,m,o;
	    cin>>n>>m>>o;
	    cin>>s1>>s2>>s3;
	    cout<<lcs(s1,s2,s3,n,m,o)<<"\n";
	}
	return 0;
}