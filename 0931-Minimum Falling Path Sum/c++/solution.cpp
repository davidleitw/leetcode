#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int minFallingPathSum(vector<vector<int>>& A) {
        m = A.size();
        n = A[0].size();
        
        for(int i = 1; i < m; ++i) {    
            for(int j = 0; j < n; ++j) {
                A[i][j] += min({
                    A[i - 1][max(0, j - 1)],
                    A[i - 1][j],
                    A[i - 1][min(j + 1, n - 1)]
                });
            }
        }     
        return *min_element(A[m - 1].begin(), A[m - 1].end());
    }
};

// Runtime: 20 ms, faster than 94.68% of C++ online submissions for Minimum Falling Path Sum.
// Memory Usage: 9.7 MB, less than 89.89% of C++ online submissions for Minimum Falling Path Sum.