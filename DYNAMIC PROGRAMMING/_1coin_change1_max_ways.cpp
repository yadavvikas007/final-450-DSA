#include<bits/stdc++.h>
using namespace std;

long long int count( int coin[], int m, int n )
    {
       
        long long int t[m+1][n+1];  //m--no. of elements , n--total sum value
   for(int i=0;i<=m;i++){           //initialisation
       for(int j=0;j<=n;j++){
           if(i==0) t[i][j]=0;
           if(j==0) t[i][j]=1;
       }
   }
   for(int i=1;i<=m;i++){           
       for(int j=1;j<=n;j++){     
           if(coin[i-1]<=j){          
               t[i][j]=(t[i][j-coin[i-1]] + t[i-1][j]);
           }            
           else t[i][j]=t[i-1][j];          
       }
   }
   return t[m][n];
    }

int main(){
    int coin[]={1,2,5,10};
    int n=4;
    int sum=73;
    cout<<count(coin,n,sum);
}