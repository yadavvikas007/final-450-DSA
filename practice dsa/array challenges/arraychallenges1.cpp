/*Problem
Isyana is given the number of visitors at her local theme park on N consecutive
days. The number of visitors on the i-th day is Vi

. A day is record breaking if it

satisfies both of the following conditions:
● The number of visitors on the day is strictly larger than the number of
visitors on each of the previous days.
● Either it is the last day, or the number of visitors on the day is strictly larger
than the number of visitors on the following day.
Note that the very first day could be a record breaking day!  */

#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int a[n + 1];
		a[n] = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (n == 1) {
			cout << "1" << endl;
			return 0;
		}
		int ans = 0;
		int curr = 0;
		int i = 0;
		while (i < n) {
			if (curr < a[i] && a[i] > a[i + 1])
				ans++;
			curr = max(curr, a[i]);
			i++;
		}
		cout << ans << endl;

	}
}