#include<bits/stdc++.h>
using namespace std;

void rotateby90(vector<vector<int> >& t, int n)             //anti clockwise
    { 
        for(int x=0;x<n/2;x++){
            for(int y=x;y<n-x-1;y++){
                int temp=t[x][y];       //saving topleft
                t[x][y]=t[y][n-1-x];        //topleft <---- topright
                t[y][n-1-x]=t[n-1-x][n-1-y];//topright <---- bottomright
                t[n-1-x][n-1-y]=t[n-1-y][x];//bottomright <---- bottomleft
                t[n-1-y][x]=temp;           //bottomleft <---- topleft(temp)
            }
        }
    }
void rotate90Clockwise(vector<vector<int>> &arr, int N)         //clockwise
{
    // printing the matrix on the basis of
    // observations made on indices.
    for (int j = 0; j < N; j++) 
    {
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}
void reverseColumns(int arr[R][C]) 
{ 
    for (int i = 0; i < C; i++) 
        for (int j = 0, k = C - 1; 
             j < k; j++, k--) 
            swap( 
                arr[j][i], arr[k][i]); 
} 
  
// Function for do transpose of matrix 
void transpose(int arr[R][C]) 
{ 
    for (int i = 0; i < R; i++) 
        for (int j = i; j < C; j++) 
            swap(arr[i][j], arr[j][i]); 
} 
  
// Function for print matrix 
void printMatrix(int arr[R][C]) 
{ 
    for (int i = 0; i < R; i++) { 
        for (int j = 0; j < C; j++) 
            cout << arr[i][j] << " "; 
        cout << '\n'; 
    } 
} 
  
// Function to anticlockwise 
// rotate matrix by 90 degree 
void rotate90(int arr[R][C])                //anticlockwise 
{ 
    transpose(arr);             //first transpose
    reverseColumns(arr);        //second reverse columns
    printMatrix(arr);
} 
int main(){
    vector< vector<int>> a={{1,2,3,4},
                            {5,6,7,8},
                            {9,10,11,12},
                            {13,14,15,16}};
    rotate90Clockwise(a,4);
    int n=4;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    } 
    
}