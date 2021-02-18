#include<bits/stdc++.h>
using namespace std;

stack<char> st;
void sortedinsert(char x){
    if(st.empty() || x>st.top())st.push(x);
    else{
        char temp=st.top();
        st.pop();
        sortedinsert(x);
        st.push(temp);
    }
}
void sort(){
    if(st.size()>0){
        char x=st.top();
        st.pop();
        sort();
        sortedinsert(x);
    }
}
int main(){
    st.push('v');
    st.push('i');
    st.push('k');
    st.push('a');
    st.push('s');
    sort();
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}