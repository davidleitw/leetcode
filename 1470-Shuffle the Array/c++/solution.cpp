#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> solve(2*n);
        
        for(int idx = 0; idx < n; ++idx) {
            solve[2*idx] = nums[idx];
            solve[2*idx+1] = nums[idx+n];
        }
        
        return solve;
    }
};

// Time: O(n)
// 8 ms, faster than 95.15% of C++ online submissions for Shuffle the Array. 
// 9.9 MB, less than 100.00% of C++ online submissions for Shuffle the Array.
