#include <iostream>
using namespace std;

int kadane(int a[], int n) {
    int currsum = 0;
    int maxsum = INT32_MIN;

    for (int i = 0; i < n; i++) {
        currsum += a[i];
        if (currsum <= 0) {
            currsum = 0;
        }
        maxsum = max(maxsum, currsum);
    }
    return maxsum;
}

int main() {
    int a[] = {1, 2, -2, 4, -4};
    cout << kadane(a, 5);
}