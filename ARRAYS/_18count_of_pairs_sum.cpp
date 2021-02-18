#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int a[], int n, int k) {
        int hash[100000]={0};
        int count=0;
        for(int i=0;i<n;i++){
            
            if(hash[a[i]]!=0){
                count++;
               // hash[k-a[i]]--;
            }
            hash[k-a[i]]++;
        }
        return count;
    }
int getPairsCount2(int arr[], int n, int k) {
        // code here
        int c=0;
        unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        if(m.find(k-arr[i])!=m.end())
        {
            c+=m[k-arr[i]]; //if duplicates exist then it is counted twice as the pair would repeat
        }
        
        m[arr[i]]++;//anyways storing the element
        
    }
    return c;
        
    }
int main(){
    int a[]={3,3,3,3};
    cout<<getPairsCount(a,4,6);
}