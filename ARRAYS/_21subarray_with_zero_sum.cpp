#include <bits/stdc++.h>
using namespace std;
 bool subArrayExists(int arr[], int n) 
{ 
    unordered_set<int> sumSet; 
    // Traverse through array and store prefix sums 
    int sum = 0; 
    for (int i = 0 ; i < n ; i++) 
    { 
        sum += arr[i]; 
        if (sum == 0 || sumSet.find(sum) != sumSet.end()) 
            return true; 
        sumSet.insert(sum); 
    } 
    return false; 
} 

int main(){
    int a[]={1,2,3,4,5,6,-1,-5};
    cout<<subArrayExists(a,8);
}