#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int day = days.size();
        int dp[366] = {0};
        int idx = 0;
        
        for(int i = 1; i < 366; ++i) {
            if(idx < day && i == days[idx]) {
                idx++;
                dp[i] = min(dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1]);
                dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[365];
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Cost For Tickets.
// Memory Usage: 9.5 MB, less than 6.63% of C++ online submissions for Minimum Cost For Tickets.