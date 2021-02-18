#include<bits/stdc++.h>
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

int main(){
    string s1="nitin";
    string s2=s1;
    reverse(s2.begin(),s2.end());
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
    cout<<"a b c d\n";
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }

}