#include <bits/stdc++.h>
using namespace std; 

// nums1只是拿來索引 
// 另一種想法 先處理nums2, 然後再利用處理完的vector根據num1來解出solution
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        
        for(int idx = 0; idx < nums1.size(); ++idx) {
            hash[nums1[idx]] = idx; // make val->index hash;
        }
        
        stack<int> s;
        vector<int> solution(nums1.size(), -1);
        
        for(int idx = 0; idx < nums2.size(); ++idx) {
            int val = nums2[idx];
            while(!s.empty() && val > nums2[s.top()]) {
                int index = s.top();
                if(hash.find(nums2[index]) != hash.end()) {
                    solution[hash[nums2[index]]] = val;
                }
                s.pop();
            }
            s.push(idx);
        }
        
        
        return solution;
    }
};

// Runtime: 8 ms, faster than 97.15% of C++ online submissions for Next Greater Element I.
// Memory Usage: 9.1 MB, less than 65.70% of C++ online submissions for Next Greater Element I.