#include<bits/stdc++.h>
using namespace std;

void countDuplicates(string s){
    int h[128]={0};
    for(int i=0;i<s.length();i++){
        h[s[i]]++;
    }
    for(int i=0;i<128;i++){
        if(h[i]>1){
            cout<<char(i)<<" "<<h[i]<<endl;
        }
    }
}
int main(){
    string s1;
    getline(cin,s1);
    countDuplicates(s1);
}