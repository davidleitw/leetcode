#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> solve;
        int size = nums.size();
        for(int idx = 0; idx < size; idx += 2) {
            for(int t = 0; t < nums[idx]; ++t) solve.push_back(nums[idx+1]);
        }
        
        return solve;
    }
};

// 4 ms, faster than 97.24% of C++ online submissions for Decompress Run-Length Encoded List.
// 10.2 MB, less than 50.60% of C++ online submissions for Decompress Run-Length Encoded List.