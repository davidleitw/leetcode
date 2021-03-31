static int n = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    struct cmp {
        bool operator()(const pair<string, int> &p1, const pair<string, int> &p2) {
            if(p1.second != p2.second) return p1.second < p2.second;
            return p1.first > p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashMap;
        for(string s: words) hashMap[s]++;
        
        vector<string> solution;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> MaxHeap(hashMap.begin(), hashMap.end());
        for(int i = 0; i < k; ++i) {
            solution.push_back(MaxHeap.top().first);
            MaxHeap.pop();
        } 
        return solution;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Top K Frequent Words.
// Memory Usage: 12.7 MB, less than 43.88% of C++ online submissions for Top K Frequent Words.