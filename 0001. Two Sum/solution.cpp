#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> solve = {};
        for(int index = 0; index < nums.size(); ++index) {
            if(hash.find(target-nums[index]) != hash.end()) {
                solve.push_back(index);
                solve.push_back(hash[target-nums[index]]);
                return solve;
            }
            hash[nums[index]] = index;
        }
        return solve;
    }
};