// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return Next larger elements


vector<long long> nextSmallerElement(vector<long long> arr, int n){
    stack<long long> st;
    vector<long long>ans;
    st.push(arr[n-1]);
    ans.push_back(-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i])
            st.pop();
        ans.push_back(st.empty() ? -1 :st.top());
        st.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        vector <long long> res = nextSmallerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}