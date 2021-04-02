class Solution {
public:
    string reorganizeString(string S) {
        int max_freq = (S.size() + 1) / 2;
        unordered_map<char, int> hashMap;
        priority_queue<pair<int, char>> maxHeap;
        for(char c: S) hashMap[c]++;
        
        for(const auto &p: hashMap) {
            if(p.second > max_freq) return "";
            maxHeap.push({p.second, p.first});
        }
        
        string solution = "";
        while(maxHeap.size() > 1) {
            pair<int, char> p1 = maxHeap.top(); maxHeap.pop();
            pair<int, char> p2 = maxHeap.top(); maxHeap.pop();
            solution.push_back(p1.second);
            solution.push_back(p2.second);
            if(p1.first > 1) maxHeap.push({p1.first - 1, p1.second});
            if(p2.first > 1) maxHeap.push({p2.first - 1, p2.second});
        }
        if(maxHeap.size() > 0) solution += maxHeap.top().second;
        return solution;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reorganize String.
// Memory Usage: 6.3 MB, less than 27.69% of C++ online submissions for Reorganize String.