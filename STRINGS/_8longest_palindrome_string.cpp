#include <bits/stdc++.h>
using namespace std;

bool check(string s,int l,int h){
    while(l<h){
        if(s[l]!=s[h]) return false;
        l++;h--;
    }
    return true;
}
string substring(string s,int l,int h){
    string ans="";
    for(int i=l;i<=h;i++) ans=ans+s[i];
    return ans;
} 
string longest_palindrome(string s){            //time: O(N^3) worst 
    string result="";
    int max=0;
    if(s.length()==0) return "";
    for(int i=0;i<s.length();i++){
	        for(int j=s.length()-1;j>=i;j--){
	            if(s[i]==s[j] && max<(j-i+1)){
	                if(check(s,i,j)){
	                    if(max<(j-i+1)){
	                        max=(j-i+1);
	                        result=substring(s,i,j);
	                    }
	                    
	                }
	            }
	        }
	    }
	    return result;
}

string longestPalSubstr(string str)             //time: O(N^2) 
{ 
    int maxLength = 1;   
    int start = 0; 
    int len = str.length(); 
    int low, high; 
    for (int i = 1; i < len; ++i) {  
        //for even palindromes
        low = i - 1;   
        high = i; 
        while (low >= 0 && high < len  && str[low] == str[high]) { 
            if (high - low + 1 > maxLength) { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
        //for odd palindromes
        low = i - 1; 
        high = i + 1; 
        while (low >= 0 && high < len  && str[low] == str[high]) { 
            if (high - low + 1 > maxLength) { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        }
       
    } 
    return substring(str,start,start+maxLength-1);
}
string longestPalindrome(string s) {
        int n=s.size();
        if(n<=0) return 0;
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++)  //base cases
            dp[i][i]=true;
        for(int i=0;i<n-1;i++){     
            dp[i][i+1]=(s[i]==s[i+1]);
        }
        for(int len=2;len<n;len++){
            for(int i=0,j=i+len;j<n;j++,i++){
                dp[i][j]=dp[i+1][j-1] && (s[i]==s[j]);
            }
        }
        int max=INT_MIN;
        int start=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] && j-i+1>max){
                    max=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start,max);
    }

int main(){
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<longestPalindrome(s);
	}
	return 0;
}