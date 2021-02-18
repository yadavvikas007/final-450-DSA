#include <bits/stdc++.h>
using namespace std;

int getInvCount(int arr[], int n)       //O(N^2)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}

long long countMerge(long long A[], long long l, long long mid, long long h)
{
    long long n1 = mid - l + 1;
    long long n2 = h - mid;
    long long int res = 0;
    long long left[n1];
    long long right[n2];

    long long i ,j, k = l;
    for(i = 0 ; i < n1 ; i++)
        left[i] = A[l+i];

    for(j = 0 ; j < n2 ; j++)
        right[j] = A[mid+j+1];

    i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            A[k++] = left[i++];
        }
        else
        {
            A[k++] = right[j++];
            res += n1-i;
        }
    }
    while(i < n1)
        A[k++] = left[i++];
    while(j < n2)
        A[k++] = right[j++];
    
    return res;
}

long long int countInversion(long long A[],long long l, long long h)
{
    long long int res = 0;
    if(l < h)   
    {
        int mid = l+(h-l)/2;

        res += countInversion(A,l,mid); 
        res += countInversion(A,mid+1,h);
        res += countMerge(A,l,mid,h);
    }
    return res;
}
long long int inversionCount(long long A[],long long N)     //O(NlogN) inhanced merge sort
{
    long long int res = countInversion(A,0,N-1);
    return res;
}

int main(){
    long long int a[]={1,2,3,6,7,4,5,8,10,9};
    cout<<inversionCount(a,10);
}
