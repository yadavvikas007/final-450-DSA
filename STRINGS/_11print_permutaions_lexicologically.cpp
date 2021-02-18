#include<bits/stdc++.h>
using namespace std;

void perm(string s,int l,int h){
    if(l==h){
        cout<<s<<" ";
    }
    else{
        for(int i=l;i<=h;i++){
            swap(s[l],s[i]);
            sort(s.begin()+l+1,s.end());    //for lexicologically order printing
            perm(s,l+1,h);          //s[l] fixed
            swap(s[l],s[i]);        //backtracking
        }
    }
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    sort(s.begin(),s.end());//for lex. printing permutaions
	    perm(s,0,s.size()-1);
	    cout<<"\n";
	}
	return 0;
}