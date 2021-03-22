class Solution {
public:
    size_t candidates_size;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> solution;
        this->candidates_size = candidates.size();
        sort(candidates.begin(), candidates.end());
        backtracking(solution, candidates, combination, 0, target);
        return solution;
    }
    
    void backtracking(vector<vector<int>> &solution, vector<int> &candidates, vector<int> &combination, int index, int remain) {
        if(remain == 0) {
            solution.push_back(combination);
            return;
        }
        
        for(int i = index; i < this->candidates_size; ++i) {
            if(candidates[i] > remain || (i > index && candidates[i] == candidates[i - 1])) continue;
            combination.push_back(candidates[i]);
            backtracking(solution, candidates, combination, i + 1, remain - candidates[i]);
            combination.pop_back();
        }
    }

};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum II.
// Memory Usage: 10.6 MB, less than 87.60% of C++ online submissions for Combination Sum II.
