#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int solution = INT_MIN;
        for(int num: nums) {
            sum = max(sum+num, num);
            solution = max(solution, sum);
        }
        return solution;
    }
};

// Runtime: 8 ms, faster than 97.34% of C++ online submissions for Maximum Subarray.
// Memory Usage: 13.2 MB, less than 68.04% of C++ online submissions for Maximum Subarray.
