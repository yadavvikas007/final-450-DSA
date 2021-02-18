#include <bits/stdc++.h>
using namespace std;
void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int l=0,mid=0,h=arr.size()-1;
        while(mid<=h){
            if(arr[mid]<a) swap(arr[mid++],arr[l++]);
            else if(arr[mid]>b) swap(arr[mid],arr[h--]);
            else mid++;
        }
    }

int main(){
    vector <int> a={10,9,8,7,6,5,4,3,2,1};
    threeWayPartition(a,3,6);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
}