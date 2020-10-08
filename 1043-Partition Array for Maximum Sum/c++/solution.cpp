#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int size = arr.size();
        vector<int> dp(size, 0);
        int max_value = INT_MIN;
        for(int i = 0; i < k; ++i) {
            max_value = max(max_value, arr[i]);
            dp[i] = max_value * (i + 1);
        }
        
        for(int i = k; i < size; ++i) {
            int max_value = INT_MIN;
            for(int j = 0; j < k && i - j > 0; ++j) {
                max_value = max(max_value, arr[i - j]);
                dp[i] = max(dp[i], max_value * (j + 1) + dp[i - j - 1]);
            }
        }
        return dp[size-1];
    }
};

// Runtime: 8 ms, faster than 99.91% of C++ online submissions for Partition Array for Maximum Sum.
// Memory Usage: 8.8 MB, less than 29.97% of C++ online submissions for Partition Array for Maximum Sum.