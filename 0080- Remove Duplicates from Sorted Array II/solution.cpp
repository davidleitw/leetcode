#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int cnt = 1;
        int index = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[index] == nums[i] && cnt < 2) {
                nums[++index] = nums[i];
                cnt++;
            } else if(nums[index] != nums[i]) {
                nums[++index] = nums[i];
                cnt = 1;
            }
        }
        return index+1;
    }
};

// Runtime: 4 ms, faster than 98.51% of C++ online submissions for Remove Duplicates from Sorted Array II.
// Memory Usage: 11.3 MB, less than 28.55% of C++ online submissions for Remove Duplicates from Sorted Array II.