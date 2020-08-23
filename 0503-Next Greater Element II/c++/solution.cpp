#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        stack<int> s;
        int length = nums.size();
        vector<int> solution(length, -1);
        
        for(int i = 0; i < 2 * length - 1; ++i) {
            int val = nums[i%length];
            while(!s.empty() && val > nums[s.top()]) {
                solution[s.top()] = val;
                s.pop();
            }
            if(i < length)
                s.push(i);
        }
        return solution;
    }
};

// Runtime: 40 ms, faster than 99.81% of C++ online submissions for Next Greater Element II.
// Memory Usage: 23.8 MB, less than 79.30% of C++ online submissions for Next Greater Element II.