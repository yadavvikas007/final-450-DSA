#include <iostream>
using namespace std;

void countsort(int a[], int n)      //O(N) time complexity ,
{
    int i, j;
    int c[3] = {0};
    for (i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    i = j = 0;
    while (j)
    {
        if (c[j] > 0)
        {
            a[i++] = j;
            c[j]--;
        }
        else j++;
    }
}
void sort012(int a[], int n)        //O(N) time complexity , O(1) space complexity
{
    int l = 0;
    int h = n - 1;
    int mid = 0;
    while (mid <= h)
    {
        if (a[mid] == 0) swap(a[l++], a[mid++]);
        if (a[mid] == 1) mid++;
        if (a[mid] == 2) swap(a[mid++], a[h--]);
    }
}
int main() {
    int t, i, j, n;
    /*cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> n;
        int a[n];
        for (j = 0; j < n; j++) cin >> a[j];
        countsort(a, n);
        for (j = 0; j < n; j++) cout << a[j];
        cout << endl;
    }*/
    int A[] = {0, 2, 1, 0, 2, 1, 0, 2, 1, 1};
    sort012(A, 10);
    for (j = 0; j < 10; j++) cout << A[j];
    cout << endl;
    return 0;
}