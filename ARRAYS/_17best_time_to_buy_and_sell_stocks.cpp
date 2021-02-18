#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& a) {     //single transaction allowed (dynamic approach)
        int minprice=INT_MAX;
        int maxprofit=0;
        for(int i=0;i<a.size();i++){
            minprice=min(minprice,a[i]);
            maxprofit=max(maxprofit,a[i]-minprice);
        }
        return maxprofit;
    }

int maxProfit2(vector<int>& prices) {       //multiple transactions allowed (greedy approach) 
        int maxprofit=0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1]>prices[i])
                maxprofit+=prices[i+1]-prices[i];
        }
        return maxprofit;
    }


int main(){
    vector<int> a={1,2,3,4,5,6,7,8,9,10};
    cout<<maxProfit(a);
}