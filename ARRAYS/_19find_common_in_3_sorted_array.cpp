#include <bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector <int> ans;
            int i=0,j=0,k=0,ct=INT_MIN;
            while(i<n1 && j<n2 && k<n3){
                if(A[i]==B[j] && A[i]==C[k]){
                    if(A[i]!=ct){
                        ans.push_back(A[i]);
                        ct=A[i];  
                    }
                    i++; j++; k++; 
                }
                else if(A[i]<B[j] && A[i]<C[k])i++;
                else if(B[j]<C[k] && B[j]<C[k])j++;
                else if(C[k]<A[i] && C[k]<B[j])k++;
            }
            return ans;
        }
int main(){
    int a[]={3,3,3};
    int b[]={3,3,3};
    int c[]={3,3,3};
    vector <int> ans=commonElements(a,b,c,3,3,3);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<"\n";

}