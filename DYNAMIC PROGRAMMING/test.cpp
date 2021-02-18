#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.pop_back();
    cout<<v.capacity();
    cout<<v.size();
}