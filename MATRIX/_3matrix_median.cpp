#include<bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &a, int n, int m){
        int min=a[0][0],max=a[0][0];
        for(int i=0;i<n;i++){
            if(a[i][0]<min) min=a[i][0];            //min element 
            if(a[i][m-1]>max) max=a[i][m-1];        //max element
        }
        int desired=(1+n*m)/2;          //desired no. of elements which are <= median
        while(min<max){
            int mid=(max+min)/2;                    //mid element of min and max 
            int count=0;
            for(int i=0;i<n;i++){
                count+=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();   
            }                           //upper_bound -----> to find the total no. of elements <= mid in a row 
            if(count<desired) min=mid+1;
            else max=mid;
        }
        return min;
    }

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a( n , vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<median(a,n,m);
}