#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
        if(n==1) return "1";
        string s="1";
        for(int i=2;i<=n;i++){
            s=s+"&";
            string t="";
            int count =1;
            for(int j=1;j<s.length();j++){
                if(s[j]!=s[j-1]){
                    t=t+to_string(count);
                    t=t+s[j-1];
                    count =1;
                }
                else count++;
            }
            s=t;
        }
        return s;
        
    }

int main(){
    int n;
    cin>>n;
    cout<<countAndSay(n);
}