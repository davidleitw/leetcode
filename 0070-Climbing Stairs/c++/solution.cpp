#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int *dp = new int[n];
        dp[0] = 1;
        dp[1] = 2;
        for(int idx = 2; idx < n; ++idx) {
            dp[idx] = dp[idx-1] + dp[idx-2];
        }
        return dp[n-1];
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 6.2 MB, less than 26.14% of C++ online submissions for Climbing Stairs.

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int step1 = 1;
        int step2 = 2;
        for(int idx = 2; idx < n; ++idx) {
            int tmp = step1 + step2;
            step1 = step2;
            step2 = tmp;
        }
        return step2;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 6.1 MB, less than 45.20% of C++ online submissions for Climbing Stairs.