#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        ios_base::sync_with_stdio(false);
        
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] > 0 && i != 0 && j != 0) {
                    matrix[i][j] = min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]) + matrix[i][j];
                }
                count += matrix[i][j];
            }
        }
        return count;
    }
};

// Runtime: 116 ms, faster than 99.40% of C++ online submissions for Count Square Submatrices with All Ones.
// Memory Usage: 24.1 MB, less than 50.28% of C++ online submissions for Count Square Submatrices with All Ones.