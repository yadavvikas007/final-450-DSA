#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2,nums1);*/
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        
        int x = nums1.size(), y = nums2.size();
        int low = 0, high = x;
        
        while(low <= high){
            int partitionX = (low + high) / 2;
            int partitionY = ((x + y + 1) / 2) - partitionX;
            
            int maxLeftX  = (partitionX == 0) ? INT_MIN : nums1.at(partitionX - 1);
            int minRightX = (partitionX == x) ? INT_MAX : nums1.at(partitionX);
            int maxLeftY  = (partitionY == 0) ? INT_MIN : nums2.at(partitionY - 1);
            int minRightY = (partitionY == y) ? INT_MAX : nums2.at(partitionY);
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                if((x + y) % 2 == 0) 
                     return ((double) max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                
                else return (double) max(maxLeftX, maxLeftY);
            }
            
            else if(maxLeftX > minRightY) 
                 high = partitionX - 1;
            else low  = partitionX + 1;
        }
        
        return 0.0;
    }

int main(){
    vector <int> nums1={1,2,3,4,5};
    vector <int> nums2={6,7,8,9,10,11,12,13,14,15};
    cout<<findMedianSortedArrays(nums1,nums2);
}