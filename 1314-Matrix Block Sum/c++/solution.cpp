#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        const int m = mat.size();
        const int n = mat[0].size();
        
        // make table
        int **dp = new int*[m];
        for(int i = 0; i < m; ++i)
            dp[i] = new int[n];
        
        dp[0][0] = mat[0][0];
        for(int idx = 1; idx < n; ++idx) dp[0][idx] = dp[0][idx-1] + mat[0][idx];
        
        for(int i = 1; i < m; ++i) {
            int sum = 0;
            for(int j = 0; j < n; ++j) {
                sum += mat[i][j];
                dp[i][j] = sum + dp[i-1][j];
            }
        }
        
        vector<vector<int>> solution(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int lx = max(0, i-K);   // left x 
                int ly = max(0, j-K);   // left y
                int rx = min(m-1, i+K); // right x
                int ry = min(n-1, j+K); // right y
                
                solution[i][j] = dp[rx][ry];
                if(lx > 0) solution[i][j] -= dp[lx-1][ry];
                if(ly > 0) solution[i][j] -= dp[rx][ly-1];
                if(lx > 0 && ly > 0) solution[i][j] += dp[lx-1][ly-1];
            }
        }
        return solution;
    }
};

// Runtime: 12 ms, faster than 97.44% of C++ online submissions for Matrix Block Sum.
// Memory Usage: 9.9 MB, less than 9.67% of C++ online submissions for Matrix Block Sum.