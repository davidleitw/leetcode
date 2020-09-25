#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        dp = nums;
        for(int idx = 1; idx < nums.size(); ++idx) {
            dp[idx] += dp[idx-1];
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0) return dp[j];
        return dp[j] - dp[i-1];
    }
private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

// Runtime: 32 ms, faster than 99.87% of C++ online submissions for Range Sum Query - Immutable.
// Memory Usage: 17.3 MB, less than 48.05% of C++ online submissions for Range Sum Query - Immutable.