#include<bits/stdc++.h>
using namespace std;

int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector <int> v;
        v.push_back(1);
        for(int x=2;x<=n;x++){
            int carry=0;
            for(int i=0;i<v.size();i++){
                int prod=v[i]*x +carry;
                v[i]=prod%10;
                carry=prod/10;
            }
            while(carry){
                v.push_back(carry%10);
                carry=carry/10;
            }
        }
        for(int i=v.size()-1;i>=0;i--)
            cout<<v[i];
        cout<<endl;
    }
	return 0;
}