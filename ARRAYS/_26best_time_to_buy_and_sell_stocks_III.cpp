#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {            //atmost 2 transactions O(N)
        int minprice1=INT_MAX, minprice2=INT_MAX;
        int maxprofit1=0,maxprofit2=0;
        for(int i=0;i<prices.size();i++){
            minprice1=min(minprice1,prices[i]);
            maxprofit1=max(maxprofit1,prices[i]-minprice1);
            
            minprice2=min(minprice2,prices[i]-maxprofit1);
            maxprofit2=max(maxprofit2,prices[i]-minprice2);
        }
        return maxprofit2;
    }
int maxProfitk(vector<int>&prices ,int k){              //O(n^2)
    int n=prices.size();
    int dp[k+1][n];
    memset(dp,0,sizeof(dp));
    for(int t=1;t<=k;t++){
        int Max=INT_MIN;
        for(int d=1;d<n;d++){
           Max=max(Max , dp[t-1][d-1]-prices[d-1]);
           dp[t][d]=max(dp[t][d-1] , Max+prices[d]);
        }
    }
    return dp[k][n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector <int> prices={1,2,3,6,3,2,1,4,5,6,0};
    cout<<maxProfitk(prices,3);
}