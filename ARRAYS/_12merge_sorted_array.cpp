#include <bits/stdc++.h>
using namespace std;

    void reorder(int a[],int n){
        int temp=a[0];
        int i=1;
        while(a[i]<temp&&i<n){
            a[i-1]=a[i];
            i++;
        }
        a[i-1]=temp;
    }
	void merge(int a1[], int a2[], int n, int m) {     //time:O(n*m)
	    for(int i=0,j=0;i<n;i++){
	        if(a1[i]>a2[j]){
	            swap(a1[i],a2[j]);
	            reorder(a2,m);
	        }
	    }
	}

    void merge1(int a1[], int a2[], int n, int m) {     //time:O( (n+m)+ O(nlogn+mlogm) )
	    for(int i=n-1,j=0 ;  i>=0&&j<m  ; i--,j++){
	        if(a1[i]>=a2[j]){
	            swap(a1[i],a2[j]);
	        }
	        else break;
	    }
	    sort(a1,a1+n);
	    sort(a2,a2+m);
	}

        int nextgap(int gap){
        if(gap<=1)return 0;
        return (gap/2)+(gap%2);
    }
	void merge2(int a1[], int a2[], int n, int m) {      //time:O((n+m)log(n+m)) 
	    int gap=n+m;
	    int i,j;
	    gap=nextgap(gap);
	    for(; gap>0 ; gap=nextgap(gap))
	    {
	        for(i=0;i+gap<n;i++)    //shifting inside a1
	            if(a1[i]>a1[i+gap])
	                swap(a1[i],a1[i+gap]);

	        for(j=gap>n?gap-n:0 ; i<n&&j<m ; i++,j++)   //shifting btw both 
	            if(a1[i]>a2[j])
	                swap(a1[i],a2[j]);
	        
	        if(j<m)
	            for(j=0;j+gap<m;j++)            //shifting inside a2
	                if(a2[j]>a2[j+gap])
	                    swap(a2[j],a2[j+gap]);

	    }
	    
	}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a1[n],a2[m];
        for(int i=0;i<n;i++) cin>>a1[i];
        for(int i=0;i<m;i++) cin>>a2[i];
        merge2(a1,a2,n,m);
        for(int i=0;i<n;i++) cout<<a1[i]<<" ";
        for(int i=0;i<m;i++) cout<<a2[i]<<" ";
    }
}