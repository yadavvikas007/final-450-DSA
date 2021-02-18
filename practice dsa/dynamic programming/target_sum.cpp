#include<bits/stdc++.h>
using namespace std;

int TargetSum(vector<int>& a, int S) {
        int sumarray=0,cnt=0;
        int n=a.size();
        for(int i=0;i<n;i++) {sumarray+=a[i]; if(a[i]==0)cnt=cnt+1;}
         if(S > sumarray)
            return 0;
        if((S+sumarray)%2!=0)
            return 0;
        int sum=(sumarray+S)/2;
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
                    if(a[i-1]==0) t[i][j]=t[i-1][j];    //ignoring 0 values
                    else if(a[i-1]<=j){          //if item[i-1] is possible selecting 
                        t[i][j]=(t[i-1][j-a[i-1]] + t[i-1][j]);    
                    }            //if possible btw selecting item[i-1] or not
                    else t[i][j]=t[i-1][j];          //not possible selecting
                }
            }
            return pow(2,cnt)*t[n][sum];
    }

int main(){
    vector <int> a={0,1};
    int sum=1;
    cout<<TargetSum(a,sum);
}