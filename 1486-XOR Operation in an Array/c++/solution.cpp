#include <iostream>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int solve = 0;
        for(int idx = 0; idx < n; ++idx) {
            solve ^= (start + 2*idx);
        }
        return solve;
    }
};

// 0 ms, faster than 100.00% of C++ online submissions for XOR Operation in an Array.
// 6 MB, less than 100.00% of C++ online submissions for XOR Operation in an Array.