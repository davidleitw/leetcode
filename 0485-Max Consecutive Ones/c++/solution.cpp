#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios_base :: sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int length = nums.size();
        int solution = 0;
        
        for(int i = 0; i < length; ++i) {
            int count = 0;
            while(i < length && nums[i]==1) {
                count++;
                i++;
            }
            if(count > solution) solution = count;
        }
        
        return solution;
    }
};

// Runtime: 60 ms, faster than 99.88% of C++ online submissions for Max Consecutive Ones.
// Memory Usage: 36.3 MB, less than 48.85% of C++ online submissions for Max Consecutive Ones. 