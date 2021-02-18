#include<bits/stdc++.h>
using namespace std;

int rodcutting(int l, int len[], int price[], int n) 
{ 
   int t[n+1][l+1];
   for(int i=0;i<=n;i++){           //initialisation
       for(int j=0;j<=l;j++){
           if(i==0 || j==0) t[i][j]=0;
       }
   }
   for(int i=1;i<=n;i++){           //for n values
       for(int j=1;j<=l;j++){       //for max weight
           if(len[i-1]<=j){          //if item[i-1] is possible selecting 
               t[i][j]=max(price[i-1]+t[i][j-len[i-1]] , t[i-1][j]);
           }            //choosing max option btw selecting item[i-1] or not
           else t[i][j]=t[i-1][j];          //not possible selecting
       }
   }
   return t[n][l];
   
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int price[n];
        for(int i=0;i<n;i++) cin>>price[i];
        int length[n];
        for(int i=0;i<n;i++) length[i]=i+1;
        cout<<rodcutting(n,length,price,n)<<"\n";
    }

}