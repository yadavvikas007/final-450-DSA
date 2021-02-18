#include <iostream>
using namespace std;

int lcs(int a, int b, string s1, string s2){
    int t[a+1][b+1];
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(j==0 || i==0) t[i][j]=0;
        }
    }
    int result=0;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j]=1+t[i-1][j-1];
                result=max(result,t[i][j]);
            }
                
            else t[i][j]=0;
        }
    }
    return result;
    
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string s1,s2;
	    cin>>s1>>s2;
	    cout<<lcs(n,m,s1,s2)<<"\n";
	}
	return 0;
}