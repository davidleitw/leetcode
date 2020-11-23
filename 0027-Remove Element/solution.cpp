#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        
        int index = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == val) continue;
            else {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
// Memory Usage: 9.1 MB, less than 82.06% of C++ online submissions for Remove Element.
