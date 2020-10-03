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

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Counting Bits.
// Memory Usage: 8 MB, less than 50.60% of C++ online submissions for Counting Bits.