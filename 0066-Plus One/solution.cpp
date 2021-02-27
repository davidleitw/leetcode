#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> solution;
        int val;
        int index = digits.size();
        int carry = 1;
        
        for(int i = index-1; i >= 0; i--) {
            val = digits[i] + carry;
            carry = val / 10;
            val = val % 10;
            solution.insert(solution.begin(), val);
        }
        if(carry) {
            solution.insert(solution.begin(), carry);
        }
        return solution;
    }
};