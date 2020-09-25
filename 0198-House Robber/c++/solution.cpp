#include <bits/stdc++.h>
using namespace std;

// 較消耗空間的寫法
class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if(length==0) return 0;
        if(length==1) return nums[0];
        
        int *dp = new int[length];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int idx = 2; idx < length; ++idx) {
            dp[idx] = max(dp[idx-1], nums[idx]+dp[idx-2]);   
        }
        return dp[length-1];
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 8 MB, less than 22.06% of C++ online submissions for House Robber.

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if(length == 0) return 0;
        
        int cur_max = 0;
        int pre_max = 0;
        for(int num: nums) {
            int temp = cur_max;
            cur_max = max(cur_max, pre_max+num);
            pre_max = temp;
        }
        
        return cur_max;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 8 MB, less than 29.24% of C++ online submissions for House Robber.