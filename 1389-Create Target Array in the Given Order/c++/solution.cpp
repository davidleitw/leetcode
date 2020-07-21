#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int size = nums.size();
        vector<int> solve;
        for(int idx = 0; idx < size; ++idx) 
            solve.insert(solve.begin() + index[idx], nums[idx]);
        
        return solve;
    }
};

// 0 ms, faster than 100.00% of C++ online submissions for Create Target Array in the Given Order.
// 8.4 MB, less than 59.04% of C++ online submissions for Create Target Array in the Given Order.