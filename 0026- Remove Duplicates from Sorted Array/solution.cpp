#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int size = nums.size();
        if(size < 2) return size;

        int index = 1;
        int val = nums[0];
        
        for(int i = 1; i < size; ++i) {
            if(nums[i] != val) {
                val = nums[i];
                nums[index++] = val;
            }
        }
        return index;
    }
};

// Runtime: 8 ms, faster than 99.69% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 14.1 MB, less than 54.92% of C++ online submissions for Remove Duplicates from Sorted Array.