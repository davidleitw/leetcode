#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            int index = binarySearch(grid[i], n - 1);
            cnt += n - index;
        }
        return cnt;
    }
    // search 從哪一個index開始是負數
    int binarySearch(vector<int> &v, int size) {
        int l = 0;
        int r = size;
        
        while(l <= r) {
            int middle = (l + r) / 2;
            if(v[middle] >= 0) {
                l = middle + 1;
            } else {
                r = middle - 1;
            }
        }
        return l;
    }
};

// Runtime: 20 ms, faster than 100.00% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
// Memory Usage: 10.8 MB, less than 93.37% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.