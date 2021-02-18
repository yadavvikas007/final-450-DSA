#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > a, int n, int m) {        //O(n*m)
	    int count=0,index=-1,ans=INT_MIN;
	    for(int i=0;i<n;i++){
	        int count=0;
	        for(int j=0;j<m;j++){
	            if(a[i][j]==1) count++;
	        }
	        if(count==m)return i;
	        if(ans<count&& count!=0){
	            index=i;
	            ans=count;
	        }
	    }
	    return index;
	}


int first(vector<int> a,int l,int h){
    if(l<=h){
        int mid=l+(h-l)/2;
        if((mid==0) || a[mid-1]==0) && a[mid]==1) return mid;   //check for a[mid] is first 1
        else if(a[mid]==0) return first(a,mid+1,h);     //if a[mid]=0 recur for right side 
        else return first(a,l,mid-1);                   //if a[mid]=1 recur for left side 
    }
    return -1;
}/*
int rowWithMax1s1(vector<vector<int>> a, int n, int m){
    int max_index=-1,index,max=-1;
    for(int i=0;i<n;i++){
        index=first(a[i],0,m-1);
        if(index!=-1 && m-index>max){
            max=m-index;
            max_index=i;
        }
        return max_index;
    }
}*/
/*int rowWithMax1s2(vector<vector<int>> a,int n ,int m){
    int i,index;
    int max_row_index=0;
    int max=first(a[0],0,m-1);      //initialising for first row
    for(int i=1;i<n;i++){
        if(max!=-1 && a[i][m-max-1]==1){    //comparing with max and searching only in greater ones
            index=first(a[i],0,m-1);
            if(index!=-1 && m-index>max){
                max=m-index;
                max_row_index=i;
            }
        }
    }
}*/

int rowwithmax1s(vector<vector<int >> a,int n,int m){
    int index=first(a[0],0,m-1);    //first occurence of 1 in a[0]
    int max_row_index=0;
    if(index==-1) index=m-1;        
    for(int i=1;i<n;i++){           //comparing all
        while(index>=0 && a[i][index==1]){
            index--;
            max_row_index=i;
        }
    }
    return max_row_index;
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
    cout<<rowwithmax1s(a,n,m);
}