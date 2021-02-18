#include<bits/stdc++.h>
using namespace std;

bool checkSubsequence(string s1,string s2){
    int n=s1.size(),m=s2.size();
   int j = 0;
   for (int i=0; i<m&&j<n; i++) 
       if (s1[j] == s2[i]) 
         j++; 
   return (j==n); 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        if(checkSubsequence(s1,s2)) cout<<"1\n";
        else cout<<"0\n";
    }
}