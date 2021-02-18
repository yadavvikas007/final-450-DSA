#include <bits/stdc++.h>
using namespace std;

void pushstack(deque<int> &dq,int x){
    dq.push_back(x);
}
int popstack(deque<int> &dq){
    int ans=dq.back();
    dq.pop_back();
    return ans;
}
int topstack(deque<int> const &dq){
    return dq.back();
}
int main(){
    deque<int> st;
    pushstack(st,10);
    pushstack(st,20);
    pushstack(st,30);
    pushstack(st,40);
    pushstack(st,50);
    cout<<topstack(st)<<" ";
    cout<<popstack(st)<<" ";
    cout<<topstack(st)<<" ";
    cout<<popstack(st)<<" ";
    cout<<topstack(st)<<" ";
    cout<<popstack(st)<<" ";
}