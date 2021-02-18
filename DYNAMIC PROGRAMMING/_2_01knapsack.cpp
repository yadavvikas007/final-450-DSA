#include<bits/stdc++.h>
using namespace std;

int knapSack(int w, int wt[], int val[], int n) 
{ 
   int t[n+1][w+1];
   for(int i=0;i<=n;i++){           //initialisation
       for(int j=0;j<=w;j++){
           if(i==0 || j==0) t[i][j]=0;
       }
   }
   for(int i=1;i<=n;i++){           //for n values
       for(int j=1;j<=w;j++){       //for max weight
           if(wt[i-1]<=j){          //if item[i-1] is possible selecting 
               t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]] , t[i-1][j]);
           }            //choosing max option btw selecting item[i-1] or not
           else t[i][j]=t[i-1][j];          //not possible selecting
       }
   }
   return t[n][w];
   
}

int main(){
    int values[] = {1,2,3};
    int weight[] = {4,5,1};
    int n=3,w=4;
    cout<<knapSack(w,weight,values,n);

}