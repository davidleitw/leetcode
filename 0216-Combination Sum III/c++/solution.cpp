class Solution {
public:
    int _k;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> solution;
        vector<int> combination;
        this->_k = k;    
        
        backtracking(solution, combination, 1, n);
        return solution;
    }
    
    void backtracking(vector<vector<int>> &solution, vector<int> &combination, int index, int remain) {
        if(combination.size() == this->_k && remain == 0) {
            solution.push_back(combination);
            return;
        }
        
        for(int i = index; i < 10; ++i) {
            if(i > remain) return;

            int r = remain - i;
            if(combination.size() == _k - 1 && r != 0) continue;
            combination.push_back(i);
            backtracking(solution, combination, i+1, r);
            combination.pop_back();
        }
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum III.
// Memory Usage: 6.4 MB, less than 84.48% of C++ online submissions for Combination Sum III.