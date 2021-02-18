#include<bits/stdc++.h>
using namespace std;

int equalPartition(int n, int a[])
    {
        long long sum=0;
        for(int i=0;i<n;i++) sum+=a[i];
        
        if(sum%2==1) return false;
        int range =sum/2;
        bool t[n+1][range+1];
            for(int i=0;i<=n;i++){           //initialisation
                for(int j=0;j<=range;j++){
                    if(i==0 && j==0) t[i][j]=true;
                    else if(i==0) t[i][j]=false;
                    else if(j==0) t[i][j]=true;
                }
            }
            for(int i=1;i<=n;i++){           //for n values
                for(int j=1;j<=range;j++){       //for max sum
                    if(a[i-1]<=j){          //if item[i-1] is possible selecting 
                        t[i][j]=t[i-1][j-a[i-1]] || t[i-1][j];
                    }            //if possible btw selecting item[i-1] or not
                    else t[i][j]=t[i-1][j];          //not possible selecting
                }
            }
        
        if(t[n][range]) return 1;
        else return 0;
    }

int main(){
    int a[] = {1,2,3};
    int n=3;
    cout<<equalPartition(n,a);

}