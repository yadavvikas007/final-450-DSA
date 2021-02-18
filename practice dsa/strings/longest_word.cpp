#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    char a[n+1];
    cin.ignore();
    cin.getline(a,n);
    int i=0;
    int currlen=0,maxlen=0;
    int st=0,maxst=0;
    while(true){
        if(a[i]==' ' || a[i]=='\0'){
            if(currlen>maxlen){
                maxlen=currlen;
                maxst=st;
            }
            st=i+1;
            currlen=0;
        }
        else currlen++;
        if(a[i]=='\0') break;
        i++;
    }
    cout<<maxlen<<endl;
    for(int i=maxst;i<maxlen;i++){
        cout<<a[i];
    }
}