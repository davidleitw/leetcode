#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> solve;
        int maxCandies = *max_element(candies.begin(), candies.end());
        
        for(int candy: candies) {
            if((candy + extraCandies) < maxCandies) 
                solve.push_back(false);
            else 
                solve.push_back(true);
        }
        return solve;
    }
};

// 0 ms, faster than 100.00% of C++ online submissions for Kids With the Greatest Number of Candies.
// 8.9 MB, less than 90.68% of C++ online submissions for Kids With the Greatest Number of Candies.