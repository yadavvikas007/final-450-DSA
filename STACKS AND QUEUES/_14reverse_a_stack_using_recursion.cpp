#include<bits/stdc++.h>
using namespace std;

stack<char> st;
void insertatbottom(char x){
    if(st.empty())st.push(x);
    else{
        char temp=st.top();
        st.pop();
        insertatbottom(x);
        st.push(temp);
    }
}
void reverseStack(){
    if(st.size()>0){
        char x=st.top();
        st.pop();
        reverseStack();
        insertatbottom(x);
    }
}
int main(){
    st.push('v');
    st.push('i');
    st.push('k');
    st.push('a');
    st.push('s');
    reverseStack();
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}