class Solution {
public:
    int integerBreak(int n) {
        if(n == 2 || n == 3) return n - 1;
        
        int dp[59] = {0};
        dp[2] = 2, dp[3] = 3;
        
        for(int i = 4; i <= n; ++i) {
            int start = i - 2;
            int max_value = INT_MIN;
            
            while(true) {
                int val = dp[start] * dp[i - start];
                if(val > max_value) {
                    max_value = val;
                    start--;
                } else {
                    dp[i] = max_value;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer Break.
// Memory Usage: 5.9 MB, less than 90.92% of C++ online submissions for Integer Break.