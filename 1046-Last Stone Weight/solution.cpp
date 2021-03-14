struct cmp {
    bool operator()(const int a, const int b) {
        return a < b;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, cmp> maxHeap(stones.begin(), stones.end());
        while(maxHeap.size() > 1) {
            int s1 = maxHeap.top(); maxHeap.pop();
            int s2 = maxHeap.top(); maxHeap.pop();
            if(s1 == s2) continue;
            
            maxHeap.push(abs(s1 - s2));
        }
        
        if(maxHeap.empty()) return 0;
        return maxHeap.top();
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
// Memory Usage: 7.6 MB, less than 61.02% of C++ online submissions for Last Stone Weight.