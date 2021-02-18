#include <bits/stdc++.h>
using namespace std;

void printsubseq(string s,string t){        //recursive solution O(2^N)
    if(s.size()==0){        //input -- ""  (empty)
        cout<<t<<"\n";
        return;
    }
    printsubseq(s.substr(1),t);     //input --(1,n-1) , output --t(not selected s[0])
    printsubseq(s.substr(1),t+s[0]);//input --(1,n-1) , output --t+s[0](selected s[0])
    
}
// set to store all the subsequences
unordered_set<string> st;
 
// Function computes all the subsequence of an string
void subsequence(string str)            //iterative solution O(N^3)
{
     
    // Iterate over the entire string
    for (int i = 0; i < str.length(); i++) 
    {
        for (int j = str.length(); j > i; j--) 
        {
            string sub_str = str.substr(i, j);
            st.insert(sub_str);
 
            // Drop kth character in the substring
            // and if its not in the set then recur
            for (int k = 1; k < sub_str.length() - 1; k++) 
            {
                string sb = sub_str;
 
                // Drop character from the string
                sb.erase(sb.begin() + k);
                subsequence(sb);
            }
        }
    }
}

int main()
{
    string a="abc";
    printsubseq(a,"");
}