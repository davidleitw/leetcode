#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        const int x = matrix.size();
        const int y = matrix[0].size();
        
        int ans = 0;
        for(int i = 0; i < x; ++i) {
            for(int j = 0; j < y; ++j) {
                matrix[i][j] -= '0';
                
                if(i!=0 && j!=0 && matrix[i][j]==1) {
                    matrix[i][j] = min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]) + matrix[i][j];
                }
                if(matrix[i][j] > ans) ans = matrix[i][j];
            }
        }
        return ans*ans;
    }
};

// Runtime: 32 ms, faster than 99.48% of C++ online submissions for Maximal Square.
// Memory Usage: 11.2 MB, less than 80.82% of C++ online submissions for Maximal Square.