#include<iostream>
#include<vector>
using namespace std;

int X[]={-1,-1,-1,0,0,1,1,1};
int Y[]={-1,0,1,-1,1,-1,0,1};

bool search2D(vector<vector<char>> arr , int r, int c, int R, int C, string str)
{
    if(arr[r][c]!=str[0])
      return false;
    int l=str.length();
    
     for(int d=0;d<8;d++)
     {
         int k;
         int rd=r+X[d];
         int cd=c+Y[d];
         for( k=1;k<l;k++)
         {
             if(rd>=R || cd>=C || rd<0 || cd<0)
               break;
             if(arr[rd][cd]!=str[k])
                 break;
             rd+=X[d];
             cd+=Y[d];
         }
         if(k==l)
           return true;
         
     }
     return false;
}


void patternSearch(vector<vector<char>> arr, int n, int m , string str)
{
     int flag=0;
     for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
        {
            if(search2D(arr,i,j,n,m,str))
              { cout<<i<<" "<<j<<", ";
                  flag=1;
              }
        }
    if(flag==0)
       cout<<"-1";
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    
	       vector <vector <char>> arr(n, vector <char> (m));
	     for(int i=0;i<n;i++)
	       for(int j=0;j<m;j++)
	       {
	          
	           cin>>arr[i][j];
	          
	       }
	    string str;
	    cin>>str;
	    patternSearch(arr,n,m,str);
	    cout<<endl;
	}
	return 0;
}