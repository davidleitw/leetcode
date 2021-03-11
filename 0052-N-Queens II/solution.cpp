class Solution {
public:
    int tableSize; 
    int totalNQueens(int n) {
        int count = 0;
        tableSize = n;
        vector<int> queensIndex(n, -1);
        solve(count, queensIndex, 0);
        return count;
    }
    
    void solve(int &count, vector<int> &queensIndex, int rowIndex) {
        if(rowIndex == tableSize) {
            count++;
        }
        
        for(int column = 0; column < tableSize; ++column) {
            if(vaildQueen(queensIndex, rowIndex, column)) {
                queensIndex[rowIndex] = column;
                solve(count, queensIndex, rowIndex+1);
                queensIndex[rowIndex] = -1;
            }
        }
    }
    
    bool vaildQueen(vector<int> &queensIndex, int row, int column) {
        for(int i = 0; i < row; ++i) {
            if(queensIndex[i] == column || absN(row - i) == absN(column - queensIndex[i])) return false; 
        }
        return true;
    }
    
    int absN(int x) {
        int mask = x >> 31;
        return (x + mask) ^ mask;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-Queens II.
// Memory Usage: 6 MB, less than 82.42% of C++ online submissions for N-Queens II.