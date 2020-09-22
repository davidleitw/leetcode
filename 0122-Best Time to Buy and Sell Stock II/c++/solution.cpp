#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for(int idx = 1; idx < prices.size(); ++idx) 
            if(prices[idx] > prices[idx-1])
                max_profit += prices[idx] - prices[idx-1];
        return max_profit;
    }
};

// Runtime: 8 ms, faster than 96.60% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 13.2 MB, less than 41.65% of C++ online submissions for Best Time to Buy and Sell Stock II.