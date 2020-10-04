#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for(int i = 0; i < 32; ++i) {
            sum += n&1;
            n >>= 1;
        }
        return sum;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
// Memory Usage: 6.2 MB, less than 10.39% of C++ online submissions for Number of 1 Bits.