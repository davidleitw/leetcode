#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> solution;
        int l1 = list1.size(), l2 = list2.size();
        if(l1 == 0 || l2 == 0) 
            return solution;
        
        int min = INT_MAX;
        unordered_map<string, int> hash;
        
        for(int i = 0; i < l1; ++i) {
            hash[list1[i]] = i;
        }
        
        for(int i = 0; i < l2; ++i) {
            string item = list2[i];
            if(hash.find(item) != hash.end()) {
                int val = hash[item] + i;
                if(min > val) {
                    min = val;
                    solution.clear();
                } 
                
                if(min == val) solution.push_back(item);
            }
        }
        
        return solution;
    }
};

// Runtime: 104 ms, faster than 99.26% of C++ online submissions for Minimum Index Sum of Two Lists.
// Memory Usage: 38.1 MB, less than 34.56% of C++ online submissions for Minimum Index Sum of Two Lists.



// 省去了clear solution的時間
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int l1 = list1.size(), l2 = list2.size();
        int Min = INT_MAX;
        string item;
        vector<string> solution;
        unordered_map<string, int> hash;
        
        for(int i = 0; i < l1; ++i) {
            hash[list1[i]] = i;
        }
        
        for(int i = 0; i < l2; ++i) {
            item = list2[i];
            if(hash.find(item) != hash.end()) {
                Min = min(Min, hash[item] + i);   
            }
        }
        for(int i = 0; i < l2; ++i) {
            item = list2[i];
            if(hash.find(item) != hash.end() && Min == hash[item] + i)
                solution.push_back(item);
        }
        
        return solution;
    }
};

// Runtime: 92 ms, faster than 100.00% of C++ online submissions for Minimum Index Sum of Two Lists.
// Memory Usage: 37.2 MB, less than 39.43% of C++ online submissions for Minimum Index Sum of Two Lists.