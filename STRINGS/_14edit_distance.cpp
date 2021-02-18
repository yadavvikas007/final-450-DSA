int minimum(int a,int b,int c){
        return min(min(a,b),c);
    }
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n==0 && m==0)return 0;
        if(n==0)return m;   //m additions
        if(m==0)return n;   //n deletions
        if(s1==s2)return 0;     //both equal
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0)dp[i][j]=j;         //
                else if(j==0)dp[i][j]=i;
                
                else if(s1[i-1]==s2[j-1])    //if equal 
                    dp[i][j]=dp[i-1][j-1];      //no operation required
                
                else dp[i][j]=1+minimum(dp[i][j-1],     //insertion s2[j] in s1
                                    dp[i-1][j],        //remove s1[i]
                                    dp[i-1][j-1]);     //replace s1[i] with s2[j]
            }
        }
        return dp[n][m];
    }