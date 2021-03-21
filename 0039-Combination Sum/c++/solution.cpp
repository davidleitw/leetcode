class Solution {
public:
    size_t candidates_size;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> solution;
        this->candidates_size = candidates.size();
        backtracking(solution, candidates, combination, 0, target);
        return solution;        
    }
    
    void backtracking(vector<vector<int>> &solution, vector<int> &candidates, vector<int>&combination, int index, int target) {
        if(target == 0) {
            solution.push_back(combination);
            return;
        }
        for(int i = index; i < this->candidates_size; ++i) {
            if(candidates[i] > target) continue;
            combination.push_back(candidates[i]);
            backtracking(solution, candidates, combination, i, target - candidates[i]);
            combination.pop_back();
            
        }
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum.
// Memory Usage: 10.7 MB, less than 91.65% of C++ online submissions for Combination Sum.