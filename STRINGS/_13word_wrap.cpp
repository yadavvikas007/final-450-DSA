#include<bits/stdc++.h>
using namespace std;

void print(int p[],int n){
    if(p[n]==1)cout<<p[n]<<" "<<n<<" ";
    else{
        print(p,p[n]-1);
        cout<<p[n]<<" "<<n<<" ";
    }
}

int main()
 {
     int t;
     cin>>t;
     while(t--){
         int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++) cin>>a[i];
	int m;
	cin>>m;
	int space[n+1][n+1];    //spaces left
	int ls[n+1][n+1];      //badness
	int c[n+1];     //optimal cost array
	int p[n+1];     //printing 
	for(int i=1;i<=n;i++){
	    space[i][i]=m-a[i];         //placing 1st first
	    for(int j=i+1;j<=n;j++){
	        space[i][j]=space[i][j-1] -a[j]-1;
	    }
	}
	
	for(int i=1;i<=n;i++){
	    for(int j=i;j<=n;j++){
	        if(space[i][j]<0)               //i--j not possible
	            ls[i][j]=INT_MAX;
	        else  if(j==n and space[i][j]>=0)   //last word
	            ls[i][j]=0;
	        else ls[i][j]=space[i][j]*space[i][j];
	    }
	}
	
	c[0]=0;
	for(int i=1;i<=n;i++){
	    c[i]=INT_MAX;
	    for(int j=1;j<=i;i++){
	        if(c[j-1]!=INT_MAX and ls[j][i]!=INT_MAX and c[j-1]+ls[j][i] <c[i]){
	            c[i]=c[j-1]+ls[i][j];
	            p[i]=j;
	        }
	    }
	}
	print(p,n);
	cout<<"\n";
     }
	
}