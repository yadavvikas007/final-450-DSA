#include <iostream>
using namespace std;

int longest_rep_subsequence(string s1,int a){
    string s2=s1;
    int b=a;
    int t[a+1][b+1];
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(j==0 || i==0) t[i][j]=0;
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(s1[i-1]==s2[j-1] && i!=j)
                t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }
    return t[a][b];
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    cout<<longest_rep_subsequence(s,n)<<"\n";
	}
	return 0;
}