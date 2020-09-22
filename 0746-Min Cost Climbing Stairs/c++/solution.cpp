#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int steps = cost.size();
        int *dp = new int[steps];
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int idx = 2; idx < steps; ++idx) {
            dp[idx] = min(dp[idx-1], dp[idx-2]) + cost[idx];
        }
        return min(dp[steps-1], dp[steps-2]);
    }
};

// Runtime: 4 ms, faster than 99.76% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 13.6 MB, less than 72.73% of C++ online submissions for Min Cost Climbing Stairs.

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        const int steps = cost.size();
        if(steps == 0) 
            return 0;
        if(steps == 1) 
            return cost[0];
        
        for(int idx = 2; idx < steps; ++idx) {
            cost[idx] += min(cost[idx-1], cost[idx-2]);
        }
        return min(cost[steps-1], cost[steps-2]);
    }
};

// Runtime: 4 ms, faster than 99.76% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 13.7 MB, less than 66.55% of C++ online submissions for Min Cost Climbing Stairs.