#include <bits/stdc++.h>
using namespace std;

int minCoins(int coin[], int m, int n) 
	{ 
	    long long int t[m+1][n+1];  //m--no. of elements , n--total sum value
	    int INF = INT_MAX-1;
   for(int i=0;i<=m;i++){           //initialisation
       for(int j=0;j<=n;j++){
           if(i==0) t[i][j]=INF;
           else if(j==0) t[i][j]=0;
           else if(i==1){
               if(j%coin[0]==0) t[i][j]=j/coin[0];
               else t[i][j]=INF;
           }
       }
   }
   for(int i=1;i<=m;i++){           
       for(int j=1;j<=n;j++){     
           if(coin[i-1]<=j){          
               t[i][j]=min(t[i][j-coin[i-1]]+1 , t[i-1][j]);
           }            
           else t[i][j]=t[i-1][j];          
       }
   }
   if(t[m][n]==INF)return -1;
   return t[m][n];
	}

int main(){
    int coin[]={1,2,5,10};
    int sum=73;
    cout<<minCoins(coin,4,73);
}