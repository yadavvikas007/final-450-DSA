#include <bits/stdc++.h>
using namespace std;

bool check_shuffle(string s1,string s2,string s3){
    if(s1.length()+s2.length()!=s3.length()) return false;
    int i=0,j=0,k=0;
    while(k!=s3.length()){
        if(i<s1.length() && s1[i]==s3[k]) i++;
        else if(j<s2.length() && s2[j]==s3[k]) j++;
        else return false;
        k++;
    }
    if(i<s1.length() || j<s2.length()) return false;
    return true;
}

int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    if(check_shuffle(s1,s2,s3)) cout<<"yes";
    else cout<<"no";
}