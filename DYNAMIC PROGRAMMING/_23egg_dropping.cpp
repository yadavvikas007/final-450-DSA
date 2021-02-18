#include <bits/stdc++.h>
using namespace std;

int eggDrop(int e, int f) 
{
    int floors=f,eggs=e;
	int dp[floors + 1][eggs + 1] = {0};
	// intializing with some cases
	// case 1. when there are 0 floors
	for(int egg = 0;egg<=eggs;egg++){
		dp[0][egg] = 0;
	}
	// case 2. when there are only 1 floor so there 
	// are only 1 way only check the first floor
	for(int egg = 0;egg<=eggs;egg++){
		dp[1][egg] = 1;
	}
	// case 3. when there are 0 eggs
	for(int floor = 0;floor <=floors;floor++){
		dp[floor][0] = 0;
	}
	// case 4. when there are 1 egg then we have to 
	// check every floor so our answer would be number of 
	// floors
	for(int floor = 0;floor <= floors;floor++){
		dp[floor][1] = floor;
	}
	// we will start filling dp matrix from 
	// floor = 2 && egg = 2
	for(int egg = 2;egg<=eggs;egg++){
		for(int floor = 2;floor<=floors;floor++){
			// choosing an ith floor between 1 - floor
			int mini = INT_MAX;
			for(int i = 1;i<=floor;i++){
				// dp[i - 1][egg-1] means to find the answer when 
				// the egg is broken at ith floor
				// dp[floor - i][egg] means to find the answer 
				// when the egg is not broken at ith floor
				int ans = 1+max(dp[i-1][egg-1], dp[floor - i][egg]);
				// by trying to check the floor i have used one trial
				//ans++;
				// taking the minimum of all possible floor 
				// possible between 1 - floor
				mini = min(mini, ans); 
			}
			// storing the answer
			dp[floor][egg] = mini;
		}
	}
	return dp[floors][eggs];
}
int main(){
    cout<<eggDrop(2,10);
}