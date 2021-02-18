#include <bits/stdc++.h>
using namespace std;

int binarysubstrings(string s){
    int zero=0,one=0,count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')zero++;
        else one++;
        if(zero==one)count++;
    }
    if(zero!=one)return -1;
    return count;
}

int main(){
    string s="001011011010100010110101";
    cout<<binarysubstrings(s);
}