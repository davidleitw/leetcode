#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int days = prices.size();
        if(days < 1) {
            return 0;
        }
        int min_price = prices[0];
        int max_price = 0;
        for(int idx = 1; idx < days; ++idx) {
            if(min_price > prices[idx]) 
                min_price = prices[idx];
            else 
                max_price = max(max_price, 
                               prices[idx]-min_price);
        }
        return max_price;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int days = prices.size();
        if(days < 1) {
            return 0;
        }
        int min_price = prices[0];
        int max_price = 0;
        
        for(int price: prices) {
            if(price < min_price) 
                min_price = price;
            else 
                max_price = max(max_price,
                               price - min_price);
        }
        return max_price;
    }
};

// Runtime: 8 ms, faster than 96.52% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 13 MB, less than 88.42% of C++ online submissions for Best Time to Buy and Sell Stock.

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int maxProfit(vector<int>& prices) {
        int max_price = 0;
        int min_price = INT_MAX;
        for(int idx = 0; idx < prices.size(); ++idx) {
            if(prices[idx] > min_price)
                max_price = max(max_price, 
                               prices[idx]-min_price);
            else
                min_price = prices[idx];
        }
        return max_price;
    }
};

// Runtime: 4 ms, faster than 99.84% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 13.2 MB, less than 32.15% of C++ online submissions for Best Time to Buy and Sell Stock.