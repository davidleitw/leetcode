class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        while(num != 0) {
            if(num & 1) {
                num -= 1;
            } else {
                num /= 2;
            }
            count++;
        } 
        return count;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
// Memory Usage: 5.7 MB, less than 94.72% of C++ online submissions for Number of Steps to Reduce a Number to Zero.