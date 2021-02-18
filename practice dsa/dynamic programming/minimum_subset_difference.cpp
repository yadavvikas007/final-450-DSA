#include <bits/stdc++.h>
using namespace std;

int minDiffernce(int a[], int n) 
	{ 
	    long long sum=0;
        for(int i=0;i<n;i++) sum+=a[i];
        
        bool t[n+1][sum+1];
            for(int i=0;i<=n;i++){           //initialisation
                for(int j=0;j<=sum;j++){
                    if(i==0 && j==0) t[i][j]=true;
                    else if(i==0) t[i][j]=false;
                    else if(j==0) t[i][j]=true;
                }
            }
            for(int i=1;i<=n;i++){           //for n values
                for(int j=1;j<=sum;j++){       //for max sum
                    if(a[i-1]<=j){          //if item[i-1] is possible selecting 
                        t[i][j]=t[i-1][j-a[i-1]] || t[i-1][j];
                    }            //if possible btw selecting item[i-1] or not
                    else t[i][j]=t[i-1][j];          //not possible selecting
                }
            }
            int diff;
            for(int i=sum/2;i>=0;i--){
                if(t[n][i]){
                    diff=sum-2*i;
                    break;
                }
            }
            return diff;
	}

int main(){
    int a[] = {1,2,3};
    int n=3;
    cout<<minDiffernce(a,n);
}