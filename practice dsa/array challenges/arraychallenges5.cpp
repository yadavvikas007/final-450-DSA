/*   maximum sum subarray;;;;;;

2. Prefix Sum Technique:
Idea: For each subarray arr[i..j], calculate its sum. Using prefix sum can
reduce time to calculate the sum of arr[i..j] to O(1)
Time Complexity: O(N^2)
Space Complexity: O(N) */

#include <iostream>
using namespace std;
 int main()
 {
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++){
        cin>>a[i];
     }
    int currsum[n+1];
    currsum[0]=0;
    for(int i=1;i<=n;i++){
        currsum[i]=currsum[i-1]+a[i-1];
    }
    int maxsum=INT32_MIN;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=0;j<i;j++){
            sum=currsum[i]-currsum[j];
            maxsum=max(maxsum,sum);
        }
    }
    cout<<maxsum<<endl;
    return 0;
 }
