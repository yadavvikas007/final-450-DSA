#include<bits/stdc++.h>
using namespace std;
void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
    }
int main(){
    int n;
    cin>>n;
    vector<char> s;
    char input;
    for(int i=0;i<n;i++){
        cin>>input;
        s.push_back(input);
    }
    reverseString(s);
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
}