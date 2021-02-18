#include <bits/stdc++.h>
using namespace std;

bool check_rotation(string s1,string s2){   
    if(s1.length()!=s2.length()) return false;
    string temp=s1+s1;
    return (temp.find(s2)!=string::npos);
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(check_rotation(s1,s2)) cout<<"yes";
    else cout<<"no";
}