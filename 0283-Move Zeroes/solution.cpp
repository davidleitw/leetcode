#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) nums[index++] = nums[i];
        }
        for(; index < nums.size(); ++index) {
            nums[index] = 0;
        }
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Move Zeroes.
// Memory Usage: 9.3 MB, less than 73.22% of C++ online submissions for Move Zeroes.