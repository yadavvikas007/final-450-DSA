#include<bits/stdc++.h>
using namespace std;

int perfectSum(int a[], int n, int sum)
	{
        int t[n+1][sum+1];
            for(int i=0;i<=n;i++){           //initialisation
                for(int j=0;j<=sum;j++){
                    if(i==0 && j==0) t[i][j]=1;
                    else if(i==0) t[i][j]=0;
                    else if(j==0) t[i][j]=1;
                }
            }
            for(int i=1;i<=n;i++){           //for n values
                for(int j=1;j<=sum;j++){       //for max sum
                    if(a[i-1]<=j){          //if item[i-1] is possible selecting 
                        t[i][j]=(t[i-1][j-a[i-1]]%1000000007 + t[i-1][j]%1000000007)%1000000007;    //prevent overflow
                    }            //if possible btw selecting item[i-1] or not
                    else t[i][j]=t[i-1][j];          //not possible selecting
                }
            }
            return t[n][sum];
	}

int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int sum=10;
    cout<<perfectSum(a,n,sum);
}