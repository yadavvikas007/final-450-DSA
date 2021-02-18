#include <bits/stdc++.h>
using namespace std;

int static t[501][501];
    
    bool ispalindrome(string s,int i,int j){
        if(i>j)return false;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++; j--;
        }
        return true;
    }
    int solve(string s,int i,int j){
        if(i>=j) return 0;
        if(ispalindrome(s,i,j)) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int mn=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int left=t[i][j]!=-1 ? t[i][j] : solve(s,i,k);
            int right=t[i][j]!=-1 ? t[i][j] :solve(s,k+1,j);
            int temp=1+left+right;
            mn=min(mn,temp);
        }
        return t[i][j]=mn;
    }
    int palindromicPartition(string str)
    {
        if(str.size()<=1)return 0;
        memset(t,-1,sizeof(t));
        return solve(str,0,str.size()-1);
    }

int main(){
    string s="11133334444333";
    cout<<palindromicPartition(s);
}