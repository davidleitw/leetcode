#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for(int idx = 1; idx <= num; ++idx) {
            if(idx%2==0) dp[idx] = dp[idx/2];
            else dp[idx] = dp[idx/2]+1;
        } 
        return dp;
    }
};

// Runtime: 4 ms, faster than 98.50% of C++ online submissions for Counting Bits.
// Memory Usage: 8.2 MB, less than 43.61% of C++ online submissions for Counting Bits.