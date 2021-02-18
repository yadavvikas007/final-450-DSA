#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int Max=0,count=1;
    for(int i=0;i<s.length();i++){
        if(s[i+1]==s[i]) count++;
        else count=1;
        Max=max(count,Max);
        
    }
    cout<<Max;
}