#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {             //time :(ON^2)   space :(ON^2)
        int n=s.size();
        if(n<=0) return 0;
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++,ans++)  //base cases
            dp[i][i]=true;
        for(int i=0;i<n-1;i++){     
            dp[i][i+1]=(s[i]==s[i+1]);
            ans+=dp[i][i+1];
        }
        for(int len=2;len<n;len++){
            for(int i=0,j=i+len;j<n;j++,i++){
                dp[i][j]=dp[i+1][j-1] && (s[i]==s[j]);
                ans+=dp[i][j];
            }
        }
        return ans;
    }

    int countSubstrings1(string s) {            //time :O(N^2)  space :O(1)
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            // odd-length palindromes, single character center
            ans += countPalindromesAroundCenter(s, i, i);

            // even-length palindromes, consecutive characters center
            ans += countPalindromesAroundCenter(s, i, i + 1);
        }

        return ans;
    }

    int countPalindromesAroundCenter(const string& ss, int lo, int hi) {
        int ans = 0;

        while (lo >= 0 and hi < ss.size()) {
            if (ss[lo] != ss[hi]) break;      // the first and last characters don't match!
            // expand around the center
            lo--;
            hi++;
            ans++;
        }

        return ans;
    }

int main(){
    string s="vikas";
    cout<<countSubstrings(s);
}