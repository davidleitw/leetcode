class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, int> p1, const pair<int, int> p2) {
            return p1.second < p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(int num: nums) {
            hashMap[num]++;
        }
        
        vector<int> solution;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> maxHeap(hashMap.begin(), hashMap.end());
        for(int i = 0; i < k; ++i) {
            solution.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        
        return solution;
    }
};