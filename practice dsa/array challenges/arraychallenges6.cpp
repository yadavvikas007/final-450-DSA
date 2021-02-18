o/*   maximum sum subarray ;;;;;

3. Kadane’s Algorithm:
Idea: Start taking the sum of the array, as soon as it gets negative, discard
the current subarray, and start a new sum.
Time Complexity: O(N)
Space Complexity: O(1)   */

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int currsum = 0;
    int maxsum = INT32_MIN;
    int ks = 0, ke = 0;

    for (int i = 0; i < n; i++) {
        currsum += a[i];
        if (currsum <= 0) {
            currsum = 0;
            ks = i + 1; ke = i + 1;
        }
        if (maxsum < currsum) ke++;
        maxsum = max(maxsum, currsum);

    }
    cout << maxsum << " " << ks << " to " << ke << endl;
    return 0;
}