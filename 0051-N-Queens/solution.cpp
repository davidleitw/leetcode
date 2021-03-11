class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solution;
        vector<int> queensIndex(n, -1);
        solve(solution, queensIndex, 0);        
        return solution;
    }
    
    void solve(vector<vector<string>> &solution, vector<int> &queensIndex, int rowIndex) {
        int n = queensIndex.size();
        if(rowIndex == n) {
            vector<string> table(n, string(n, '.'));
            for(int i = 0; i < n; ++i) table[i][queensIndex[i]] = 'Q';
            solution.push_back(table);
        }
        
        for(int column = 0; column < n; ++column) {
            if(vaildQueen(queensIndex, rowIndex, column)) {
                queensIndex[rowIndex] = column;
                solve(solution, queensIndex, rowIndex+1);
                queensIndex[rowIndex] = -1;
            }
        }
    }
    
    bool vaildQueen(vector<int> &queensIndex, int row, int column) {
        for(int i = 0; i < row; ++i) {
            if(queensIndex[i] == column || abs(row - i) == abs(column - queensIndex[i])) return false; 
        }
        return true;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-Queens.
// Memory Usage: 7.3 MB, less than 76.70% of C++ online submissions for N-Queens.