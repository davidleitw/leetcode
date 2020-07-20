#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> solve(n);
        vector<pair<int, int>> pnums(n);
        
        for(int idx = 0; idx < n; ++idx) pnums[idx] = pair<int, int>{nums[idx], idx};
        sort(pnums.begin(), pnums.end());
        
        solve[pnums[0].second] = 0;
        for(int idx = 1; idx < n; ++idx) {
            int tmp = idx-1;
            int count = 0;
            while((tmp>=0) && (pnums[idx].first==pnums[tmp].first)) {
                tmp--;
                count++;
            }
            solve[pnums[idx].second] = idx-count;
        }
            
        return solve;
    }
};

// 8 ms, faster than 94.84% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
// 10.4 MB, less than 43.60% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.