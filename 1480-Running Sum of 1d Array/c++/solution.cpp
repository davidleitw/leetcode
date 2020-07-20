#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> solve;
        int sum = 0;
        
        for(int idx = 0; idx < nums.size(); ++idx) {
            sum += nums[idx];
            solve.push_back(sum);
        }
        return solve;
    }
};

// 0 ms, faster than 100.00% of C++ online submissions for Running Sum of 1d Array.
// 8.7 MB, less than 40.00% of C++ online submissions for Running Sum of 1d Array.