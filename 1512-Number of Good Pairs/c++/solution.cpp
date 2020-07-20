#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int solve = 0;
        int nsize = nums.size();
        unordered_map<int, int> hash;
        
        for(int idx = 0; idx < nsize; ++idx) {
            // 如果遇到還沒出現過得值 就加到hash裡頭
            if(hash.find(nums[idx]) == hash.end())
                hash[nums[idx]] = 0;
            else {
                // 如果出現一次以上, 先++, 例如出現第三次=>代表前面有兩個一樣的數字, 所以hash[nums[idx]]會 = 2
                hash[nums[idx]]++;
                solve += hash[nums[idx]];
            }
        }
        return solve;
    }
};

// 0 ms, faster than 100.00% of C++ online submissions for Number of Good Pairs. 
// 7.5 MB, less than 100.00% of C++ online submissions for Number of Good Pairs.
