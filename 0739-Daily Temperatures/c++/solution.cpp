#include <bits/stdc++.h>
using namespace std; 

// save pair in stack solution. 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        const int size = T.size();
        vector<int> solution(size);
        stack<pair<int, int>> s; // first interger is index, second interger is temperature. 
        
        for(int i = 0; i < size; ++i) {
            while(!s.empty() && s.top().second < T[i]) {
                int index = s.top().first;
                solution[index] = i - index;
                s.pop();
            }
            s.push({i, T[i]});
        }
        
        return solution;
    }
};

// only save index in stack solution. 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        const int size = T.size();
        vector<int> solution(size);
        stack<int> s;
        
        for(int idx = 0; idx < size; ++idx) {
            while(!s.empty() && T[idx] > T[s.top()]) {
                int index = s.top();
                solution[index] = idx - index;
                s.pop();
            }
            s.push(idx);
        }
        
        return solution;
    }
};

// Runtime: 104 ms, faster than 95.18% of C++ online submissions for Daily Temperatures.
// Memory Usage: 37.3 MB, less than 41.23% of C++ online submissions for Daily Temperatures.
